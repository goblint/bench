#!/usr/bin/ruby
require 'fileutils'
Dir.chdir(File.dirname(__FILE__))
goblint = File.expand_path("../analyzer/goblint")
fail "Please run script from goblint dir!" unless File.exist?(goblint)
$vrsn = `#{goblint} --version`
results = "bench_result"
Dir.mkdir(results) unless Dir.exist?(results)
$testresults = File.expand_path("bench_result") + "/"
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
  puts "Warning: No syntax highlighter installed (code2html, source-highlight, pygmentize)."
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

def print_res (i)
  File.open($theresultfile, "w") do |f|
    f.puts "<html>"
    f.puts $header
    f.puts "<body>"
    f.puts "<p>Benchmarking in progress: #{i}/#{$projects.length} <progress value=\"#{i}\" max=\"#{$projects.length}\" /></p>" unless i.nil?
    f.puts "<table border=2 cellpadding=4 style=\"font-size: 90%\">"
    gname = ""
    $projects.each do |p|
      if p.group != gname then
        gname = p.group
        f.puts "<tr><th colspan=#{4+$analyses.size}>#{gname}</th></tr>"
        if $print_desc then
          f.puts "<tr><th>#</th><th>Name</th><th>Description</th><th>Size</th>"
        else
          f.puts "<tr><th>#</th><th>Name</th><th>Size</th>"
        end
        $analyses.each do |a|
          aname = a[0]
          f.puts "<th>#{aname}</th>"
        end
      end
      f.puts "<tr>"
      f.puts p.to_html
      $analyses.each do |a|
        aname = a[0]
        outfile = p.name + ".#{aname}.txt"
        if File.exist?($testresults + outfile) then
          File.open($testresults + outfile, "r") do |g|
            lines = g.readlines
            safely = lines.grep(/[^n]safe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            vulner = lines.grep(/vulnerable:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            unsafe = lines.grep(/unsafe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
            uncalled = lines.grep(/will never be called/).reject {|x| x =~ /__check/}.size
            res = lines.grep(/^TIMEOUT\s*(.*) s.*$/) { |x| $1 }
            if res == [] then
              dur = lines.grep(/^Duration: (.*) s/) { |x| $1 }
              cod = lines.grep(/^EXITCODE\s*(.*)$/) { |x| $1 }
              if cod == [] and not dur == [] then
                thenumbers =  "<font color=\"green\">#{safely}</font>; "
                thenumbers << "<font color=\"orange\">#{vulner}</font> + "
                thenumbers << "<font color=\"red\">#{unsafe}</font>"
                thenumbers << "; <font color=\"magenta\">#{uncalled}</font>" if uncalled > 0
                f.puts "<td><a href=\"#{outfile}.html\">#{"%.2f" % dur} s</a> (#{thenumbers})</td>"
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
      f.puts "</tr>"
    end
    f.puts "</table>"
    f.print "<p style=\"font-size: 80%; white-space: pre-line\">"
    f.puts "Last updated: #{Time.now.strftime("%Y-%m-%d %H:%M:%S %z")}"
    f.puts "#{$vrsn}"
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
file = "bench.txt"
$linuxroot = "https://elixir.bootlin.com/linux/v4.0/source/"
File.symlink("index/concrat.txt",file) unless FileTest.exist? file

FileUtils.cp(file,File.join($testresults, "bench.txt"))

$analyses = []
File.open(file, "r") do |f|
  id = 0
  while line = f.gets
    next if line =~ /^\s*$/
    if line =~ /Group: (.*)/
      gname = $1.chomp
      skipgrp << gname if line =~ /SKIP/
    elsif line =~ /(.*): ?(.*)/
      $analyses << [$1,$2]
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
  outfiles = $testresults + File.basename(filename,".c") + ".*"
  `rm -f #{outfiles}`
  if p.url == "generate!" then
    system(highlighter.call(p.path, $testresults + p.name + ".html"))
    p.url = p.name + ".html"
  end
  puts "Analysing #{filename} (#{p.id}/#{$projects.length})"
  $analyses.each do |a|
    aname = a[0]
    aparam = a[1]
    print "  #{format("%*s", -maxlen, aname)}"
    STDOUT.flush
    outfile = $testresults + p.name + ".#{aname}.txt"
    starttime = Time.now
    #Add --sets cilout /dev/null to ignore CIL output.
    cmd = "#{goblint} --set dbg.timeout #{timeout} #{aparam} #{filename} #{p.params}  --enable allglobs --enable dbg.timing.enabled 1>#{outfile} 2>&1"
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
