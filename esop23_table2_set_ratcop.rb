#!/usr/bin/ruby
require 'fileutils'
Dir.chdir(File.dirname(__FILE__))
goblint = File.expand_path("../analyzer/goblint")
goblint_conf = File.expand_path("../analyzer/conf/traces-rel.json")
compare = File.expand_path("../analyzer/apronPrecCompare")
fail "Please run script from goblint dir!" unless File.exist?(goblint)
$vrsn = `#{goblint} --version`
results = "esop23_table2_set_ratcop"
Dir.mkdir(results) unless Dir.exist?(results)
$testresults = File.expand_path("esop23_table2_set_ratcop") + "/"
bench = "./"
linux = bench + "linux/"

cmds = {"code2html" => lambda {|f,o| "code2html -l c -n #{f} 2> /dev/null 1> #{o}"},
        "source-highlight" => lambda {|f,o| "source-highlight -n -i #{f} -o #{o}"},
        "pygmentize" => lambda {|f,o| "pygmentize -O full,linenos=1 -o #{o} #{f}"}
       }
highlighter = nil
cmds.each do |name, cmd|
  # if `which #{cmd} 2> /dev/null`.empty? then
  if ENV['PATH'].split(':').map {|f| File.executable? "#{f}/#{name}"}.include?(true) then
    highlighter = cmd
    break
  end
end
if highlighter.nil? then
  # puts "Warning: No syntax highlighter installed (code2html, source-highlight, pygmentize)."
  highlighter = lambda {|f,o| "cp #{f} #{o}"}
end

class Project
  attr_reader :id, :name, :group, :path
  attr_accessor :url, :params
  def initialize(id, name, size, url, group, path, params)
    @id       = id
    @name     = name
    @size     = size
    @url      = url
    @group    = group
    @path     = path
    @params   = params
  end
  def to_html
    "<td>#{@id}</td><td><a href=\"#{@url}\">#{@name}</a></td>\n" + "<td>#{@size}</td>\n"
  end
  def to_s
    "#{@name}"
  end
end
$projects = []

$header = <<END
<head>
  <title>Benchmarks on #{`uname -n`.chomp}</title>
  <style type="text/css">
    A:link {text-decoration: none}
    A:visited {text-decoration: none}
    A:active {text-decoration: none}
    A:hover {text-decoration: underline}
</style>
</head>
END
$theresultfile = File.join($testresults, "index.html")


def outfile_name (p,aname)
  File.basename(File.dirname(p)) + "_" + File.basename(p,".c") + ".#{aname}.txt"
end

def print_res (i)
  File.open($theresultfile, "w") do |f|
    f.puts "<html>"
    f.puts $header
    f.puts "<body>"
    f.puts "<p>Benchmarking in progress: #{i}/#{$projects.length} <progress value=\"#{i}\" max=\"#{$projects.length}\" /></p>" unless i.nil?
    f.puts "<table border=2 cellpadding=4 style=\"font-size: 90%\">"
    gname = ""
    first_group = true
    total_assert_count = 0
    $projects.each do |p|
      if p.group != gname then
        if first_group == false then
          f.puts "<tr>"
          f.puts "<td colspan=3> Summary </td>"
          f.puts "<td>#{$analyses[0][4]}</td>"
          $analyses.each do |a|
            success = a[2]
            unknown = a[3]
            total = a[4]

            thenumbers = ""
            if success == total then
              thenumbers << "<font color=\"green\" title=\"success\">✔️</font> "
            elsif unknown == total then
              thenumbers << "<font color=\"red\" title=\"unknown\">❌</font>"
            else
              thenumbers << "<font color=\"green\" title=\"success\">✔️<b>#{success}</b></font> "
              thenumbers << "<font color=\"red\" title=\"unknown\">❌<b>#{unknown}</b></font>"
            end

            f.puts "<td> #{thenumbers}</td>"
            a[2] = 0
            a[3] = 0
            a[4] = 0
          end
          f.puts "</tr>"
        else
          first_group = false
        end
        gname = p.group
        f.puts "<tr><th colspan=#{4+$analyses.size+1}>#{gname}</th></tr>"
        if $print_desc then
          f.puts "<tr><th>#</th><th>Name</th><th>Description</th><th>Size</th><th>Asserts</th>"
        else
          f.puts "<tr><th>#</th><th>Name</th><th>Size</th><th>Asserts</th>"
        end
        $analyses.each do |a|
          aname = a[0]
          f.puts "<th>#{aname}</th>"
        end
      end
      f.puts "<tr>"
      f.puts p.to_html
      first_one = true
      $analyses.each do |a|
        aname = a[0]
        outfile = outfile_name(p.path,aname)
        if File.exists?($testresults + outfile) then
          File.open($testresults + outfile, "r") do |g|
            lines = g.readlines
            # safely = lines.grep(/[^n]safe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            # vulner = lines.grep(/vulnerable:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            # unsafe = lines.grep(/unsafe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            uncalled = lines.grep(/will never be called/).reject {|x| x =~ /__check/}.size
            live = lines.grep(/Live lines: ([0-9]*)/) { |x| $1.to_i } .first
            dead = lines.grep(/Found dead code on ([0-9]*) line/) { |x| $1.to_i } .first
            total = lines.grep(/Total lines \(logical LoC\): ([0-9]*)/) { |x| $1.to_i } .first
            threads = lines.grep(/Encountered number of thread IDs \(unique\): ([0-9]*) /) { |x| $1.to_i } .first
            uniques =  lines.grep(/Encountered number of thread IDs \(unique\): [0-9]* \(([0-9]*)\)/) { |x| $1.to_i } .first
            mpr_r = lines.grep(/Max number of protected: ([0-9]*)/) { |x| $1.to_i }
            if mpr_r.length == 0 then
              max_protected = 0
            else
              max_protected = mpr_r.first
            end
            spr_r = lines.grep(/Sum protected: ([0-9]*)/) { |x| $1.to_i }
            if spr_r.length == 0 then
              sum_protected = 0
            else
              sum_protected = spr_r.first
            end
            mtx_r = lines.grep(/Num mutexes: ([0-9]*)/) { |x| $1.to_i }
            if mtx_r.length == 0 then
              mutexes = 0
              avg_protected = 0
            else
              mutexes = mtx_r.first
              if mutexes > 0 then
                avg_protected = sum_protected / mutexes
              else
                avg_protected = 0
              end
            end
            success = lines.grep(/\[Success\]\[Assert\]/).size
            unknown = lines.grep(/\[Warning\]\[Assert\]/).size
            error = lines.grep(/\[Error\]\[Assert\]/).size

            assert_count = success + unknown + error

            res = lines.grep(/TIMEOUT\s*(\d*) s.*$/) { |x| $1 }
            if res == [] then
              dur = lines.grep(/^Duration: (.*) s/) { |x| $1 }
              cod = lines.grep(/EXITCODE\s*(.*)$/) { |x| $1 }
              if cod == [] and not dur == [] then
                if first_one then
                  f.puts "<td> #{assert_count}</td>"
                  first_one = false
                end

                # thenumbers =  "<font color=\"green\" title=\"safe memory locations\">#{safely}</font>; "
                # thenumbers << "<font color=\"orange\" title=\"vulnerable memory locations\">#{vulner}</font> + "
                # thenumbers << "<font color=\"red\" title=\"unsafe memory locations\">#{unsafe}</font>; "
                thenumbers = ""

                a[2] += success
                a[3] += unknown
                a[4] += assert_count


                # thenumbers << "<font color=\"magenta\" title=\"uncalled functions\">#{uncalled}</font>; " if uncalled > 0
                # thenumbers << "<b><font color=\"red\" title=\"dead lines\">#{dead}</font></b>+"
                # thenumbers << "<b title=\"live lines\">#{live}</b>="
                if success == assert_count then
                  thenumbers << "<font color=\"green\" title=\"success\">✔️</font> "
                elsif unknown == assert_count then
                  thenumbers << "<font color=\"red\" title=\"unknown\">❌</font>"
                else
                  thenumbers << "<font color=\"green\" title=\"success\">✔️<b>#{success}</b></font> "
                  thenumbers << "<font color=\"red\" title=\"unknown\">❌<b>#{unknown}</b></font>"
                end

                f.puts "<td> #{thenumbers}</td>"
              else
                f.puts "<td><a href=\"#{outfile}\">failed (code: #{cod.first.to_s})</a></td>"
              end
            else
	      f.puts "<td><a href=\"#{outfile}\">#{res.first.to_s} s</a> (limit)</td>"
            end
          end
        else
          f.puts "<td>N/A</a></td>"
        end
      end

      gb_file = $testresults + File.basename(p.path,".c") + ".mutex.txt"
      f.puts "</tr>"
      f.puts "</tr>"
    end

    f.puts "<tr>"
    f.puts "<td colspan=3> Summary </td>"
    f.puts "<td>#{$analyses[0][4]}</td>"
    $analyses.each do |a|
      success = a[2]
      unknown = a[3]
      total = a[4]

      thenumbers = ""
      if success == total then
        thenumbers << "<font color=\"green\" title=\"success\">✔️</font> "
      elsif unknown == total then
        thenumbers << "<font color=\"red\" title=\"unknown\">❌</font>"
      else
        thenumbers << "<font color=\"green\" title=\"success\">✔️<b>#{success}</b></font> "
        thenumbers << "<font color=\"red\" title=\"unknown\">❌<b>#{unknown}</b></font>"
      end

      f.puts "<td> #{thenumbers}</td>"


      a[2] = 0
      a[3] = 0
      a[4] = 0
    end
    f.puts "</tr>"


    f.puts "</table>"
    f.print "<p style=\"font-size: 80%; white-space: pre-line\">"
    f.puts "Last updated: #{Time.now.strftime("%Y-%m-%d %H:%M:%S %z")}"
    f.puts "#{$vrsn}"
    f.puts "Total number of asserts in benchmark files: #{total_assert_count}"
    f.puts "</p>"
    f.puts "</body>"
    f.puts "</html>"
  end
end

#Command line parameters

timeout = 900
timeout = ARGV[0].to_i unless ARGV[0].nil?
only = ARGV[1] unless ARGV[1].nil?
if only == "group" then
  only = nil
  thegroup = ARGV[2]
end

#processing the input file

skipgrp = []
file = "index/traces-rel-ratcop.txt"
$linuxroot = "https://elixir.bootlin.com/linux/v4.0/source/"

# FileUtils.cp(file,File.join($testresults, "bench.txt"))
# File.open(file, "r") do |f|
#   id = 0
#   while line = f.gets
#       print line
#   end
# end


$analyses = []
File.open(file, "r") do |f|
  id = 0
  while line = f.gets
    next if line =~ /^\s*$/
    if line =~ /Group: (.*)/
      gname = $1.chomp
      skipgrp << gname if line =~ /SKIP/
    elsif line =~ /(.*): ?(.*)/
      $analyses << [$1,$2,0,0,0]
    else
      name = line.chomp
      url = f.gets.chomp
      path = f.gets.chomp
      params = f.gets.chomp
      params = "" if params == "-"
      if url == "linux!" then
        params = "--enable kernel " + params
        url = $linuxroot + path
        path = File.expand_path(path, linux)
      else
        path = File.expand_path(path, bench)
      end
      size = `wc -l #{path}`.split[0] + " lines"
      id += 1
      p = Project.new(id,name,size,url,gname,path,params)
      $projects << p
    end
  end
end

#Process linux results!

$fileheader = <<END
<html>
  <head>
    <title>Benchmarks on #{`uname -n`.chomp}</title>
    <style type="text/css">
      body { white-space: pre; font-family: monospace }
      a { color: inherit }
    </style>
  </head>
  <body>
END


def proc_linux_res(resultfile, url, filename)
  File.open(resultfile, "r") do |f|
    File.open(resultfile + ".html", "w") do |o|
      o.puts $fileheader
      while line = f.gets
        line.sub!(/\@(#{filename}:(\d+))/, "@<a href=\" #{url}#L\\2\">\\1</a>")
        if line =~ /race with/
          o.puts '<font color="red">' + line.chop + "</font>"
        else
          o.puts line
        end
      end
      o.puts "</body>"
      o.puts "</html>"
    end
  end
end


#analysing the files
gname = ""
maxlen = $analyses.map { |x| x[0].length }.max + 1
$projects.each do |p|
  next if skipgrp.member? p.group
  next unless thegroup.nil? or p.group == thegroup
  next unless only.nil? or p.name == only
  if p.group != gname then
    gname = p.group
    puts gname
  end
  filepath = p.path
  dirname = File.dirname(filepath)
  filename = File.basename(filepath)
  Dir.chdir(dirname)
  outfiles = $testresults + File.basename(dirname) + ".*"
  `rm -f #{outfiles}`
  if p.url == "generate!" then
    system(highlighter.call(p.path, $testresults + p.name + ".html"))
    p.url = p.name + ".html"
  end
  puts "Analysing #{filename} (#{p.id}/#{$projects.length})"
  precfiles = []
  $analyses.each do |a|
    aname = a[0]
    aparam = a[1]
    print "  #{format("%*s", -maxlen, aname)}"
    STDOUT.flush
    outfile = $testresults + outfile_name(p.path, aname)
    precfile = $testresults + outfile_name(p.path, aname) + ".#{aname}.prec"
    starttime = Time.now
    #Add --sets cilout /dev/null to ignore CIL output.
    cmd = "#{goblint} --conf #{goblint_conf} --set dbg.timeout #{timeout} #{aparam} #{filename} #{p.params} --enable allglobs --enable dbg.timing.enabled -v  --disable sem.assert.refine  1>#{outfile} 2>&1"
    system(cmd)
    status = $?.exitstatus
    endtime   = Time.now
    File.open(outfile, "a") do |f|
      f.puts "\n=== APPENDED BY BENCHMARKING SCRIPT ==="
      f.puts "Analysis began: #{starttime}"
      f.puts "Analysis ended: #{endtime}"
      f.puts "Duration: #{format("%.02f", endtime-starttime)} s"
      f.puts "Goblint params: #{cmd}"
      f.puts $vrsn
    end
    if status != 0 then
      if status == 124 then
        puts "-- Timeout!"
        `echo "TIMEOUT                    #{timeout} s" >> #{outfile}`
      else
        puts "-- Failed!"
        `echo "EXITCODE                   #{status}" >> #{outfile}`
      end
    else
      puts "-- Done!"

    end
    print_res p.id
    proc_linux_res(outfile, p.url, filename)
  end
end
print_res nil
puts ("Results: " + $theresultfile)
