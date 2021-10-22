#!/usr/bin/ruby
require 'fileutils'
Dir.chdir(File.dirname(__FILE__))
$goblint = File.expand_path("../analyzer/goblint")
$goblint_conf = File.expand_path("index/incremental.json")
fail "Please run script from goblint dir!" unless File.exist?($goblint)
$vrsn = `#{$goblint} --version`
results = "bench_result"
Dir.mkdir(results) unless Dir.exist?(results)
$testresults = File.expand_path("bench_result") + "/"
bench = "./"
linux = bench + "linux/"
$compare = true

cmds = {"code2html" => lambda {|f,o| "code2html -l c -n #{f} 2> /dev/null 1> #{o}"},
        "source-highlight" => lambda {|f,o| "source-highlight -n -i #{f} -o #{o}"},
        "pygmentize" => lambda {|f,o| "pygmentize -O full,linenos=1 -o #{o} #{f}"}
       }
$highlighter = nil
cmds.each do |name, cmd|
  # if `which #{cmd} 2> /dev/null`.empty? then
  if ENV['PATH'].split(':').map {|f| File.executable? "#{f}/#{name}"}.include?(true) then
    $highlighter = cmd
    break
  end
end
if $highlighter.nil? then
  puts "Warning: No syntax highlighter installed (code2html, source-highlight, pygmentize)."
  $highlighter = lambda {|f,o| "cp #{f} #{o}"}
end

class Project
  attr_reader :id, :name, :group, :path, :patches, :size
  attr_accessor :url, :params
  def initialize(id, name, size, url, group, path, params, patches)
    @id       = id
    @name     = name
    @size     = size
    @url      = url
    @group    = group
    @path     = path
    @params   = params
    @patches  = patches
  end
  def to_html
    "<td>#{@id}</td><td><a href=\"#{@url}\">#{@name}</a></td>\n" + "<td>#{@size}</td>\n"
  end
  def to_s
    "#{@name}"
  end
end

# class Patch
#   attr_reader :name, :path
#   attr_accessor :url,
#   def initialize(size, url, group, path, params, patches)
#     @size     = size
#     @url      = url
#     @path     = path
#   end
#   def to_html
#     "<td>-</td><td><a href=\"#{@url}\">#{@name}</a></td>\n" + "<td>#{@size}</td>\n"
#   end
#   def to_s
#     "#{@name}"
#   end
# end

$projects = []

$header = <<END
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8"/>
  <title>Benchmarks on #{`uname -n`.chomp}</title>
  <style>
    A:link {text-decoration: none}
    A:visited {text-decoration: none}
    A:active {text-decoration: none}
    A:hover {text-decoration: underline}
</style>
</head>
END
$theresultfile = File.join($testresults, "index.html")

def print_file_res (f, path)
  first = true
  $analyses.each do |a|
    aname = a[0]
    outfile = File.basename(path,".c") + ".#{aname}.txt"
    if File.exists?($testresults + outfile) then
      File.open($testresults + outfile, "r") do |g|
        lines = g.readlines
        vars, evals = lines.grep(/vars = (\d*).*evals = (\d+)/) { |x| [$1.to_i, $2.to_i] } .first
        res = lines.grep(/^TIMEOUT\s*(.*) s.*$/) { |x| $1 }
        if res == [] then
          dur = lines.grep(/^Duration: (.*) s/) { |x| $1 }
          cod = lines.grep(/^EXITCODE\s*(.*)$/) { |x| $1 }
          if cod == [] and not dur == [] then
            if $compare then
              if not first then 
                compfile = "#{outfile}.compare.txt"
                complines = File.readlines($testresults + compfile)
                msg = ""
                msg << "⊑" if complines.grep(/left = [1-9]/).any?
                msg << "≸" if complines.grep(/incomparable = [1-9]/).any?
                msg << "⊒" if complines.grep(/\<right = [1-9]/).any?
                msg = "=" if msg == ""
                thenumbers = "<a href=\"#{compfile}\">#{msg}</a>"
              end
            else
              safely = lines.grep(/[^n]safe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              vulner = lines.grep(/vulnerable:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              unsafe = lines.grep(/unsafe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              uncalled = lines.grep(/will never be called/).reject {|x| x =~ /__check/}.size
              thenumbers =  "<font color=\"green\">#{safely}</font>; "
              thenumbers << "<font color=\"orange\">#{vulner}</font> + "
              thenumbers << "<font color=\"red\">#{unsafe}</font>"
              thenumbers << "; <font color=\"magenta\">#{uncalled}</font>" if uncalled > 0
            end
            thenumbers = " (#{thenumbers})" unless thenumbers.nil?
            f.puts "<td><a href=\"#{outfile}.html\">#{"%.2f" % dur} s / #{vars} vars / #{evals} evals</a>#{thenumbers}</td>"
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
  first = false
  end
end

def print_res (i)
  File.open($theresultfile, "w") do |f|
    f.puts $header
    f.puts "<body>"
    f.puts "<p>Benchmarking in progress: #{i}/#{$projects.length} <progress value=\"#{i}\" max=\"#{$projects.length}\" /></p>" unless i.nil?
    f.puts "<table border=2 cellpadding=4 style=\"font-size: 90%\">"
    gname = ""
    $projects.each do |p|
      if p.group != gname then
        gname = p.group
        f.puts "<tr><th colspan=#{3+$analyses.size}>#{gname}</th></tr>"
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
      print_file_res(f, p.path)
      f.puts "</tr>"
      p.patches.each do |pfile|
        f.puts "<tr>"
        pname = File.basename(pfile)
        `cp #{pfile} #{$testresults + pname}`
        f.puts "<td>-</td><td><a href=\"#{pname}\">#{pname}</a></td>\n" + "<td><a href=\"#{pname}.html\">patched</a></td>\n"
        print_file_res(f, pfile)
        f.puts "</tr>"
      end
    end
    f.puts "</table>"
    f.print "<p style=\"font-size: 80%; white-space: pre-line\">"
    f.puts "Last updated: #{Time.now.strftime("%Y-%m-%d %H:%M:%S %z")}"
    f.puts "#{$vrsn}"
    f.puts "Goblint base configuration: <a href=\"conf.json\">conf.json</a>."
    f.puts "</p>"
    f.puts "</body>"
    f.puts "</html>"
  end
end

#Command line parameters

$timeout = 900
$timeout = ARGV[0].to_i unless ARGV[0].nil?
only = ARGV[1] unless ARGV[1].nil?
if only == "group" then
  only = nil
  thegroup = ARGV[2]
end

#processing the input file

skipgrp = []
file = "index/interactive.txt"
$linuxroot = "https://elixir.bootlin.com/linux/v4.0/source/"

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
      patches = Dir["#{path.chomp(".c")}*.patch"]
      p = Project.new(id,name,size,url,gname,path,params,patches.sort)
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


$maxlen = $analyses.map { |x| x[0].length }.max + 1
def analyze_project(p, save)
  filepath = p.path
  dirname = File.dirname(filepath)
  filename = File.basename(filepath)
  resname = File.basename(p.name,".c")
  Dir.chdir(dirname)
  outfiles = $testresults + resname + ".*"
  `rm -f #{outfiles}`
  if not p.url.start_with? "http" then
    system($highlighter.call(p.path, $testresults + resname + ".html"))
    p.url = p.name + ".html"
  end
  puts "Analysing #{resname} (#{p.id}/#{$projects.length})"
  first = true
  $analyses.each do |a|
    aname = a[0]
    aparam = a[1]
    if first then
      aparam += " --enable incremental.save " if save
      aparam += " --enable incremental.only-rename " if not save
      aparam += " --set save_run original " if $compare
    else
      aparam += " --enable incremental.load "
      aparam += " --set save_run increment " if $compare
    end
    print "  #{format("%*s", -$maxlen, aname)}"
    STDOUT.flush
    outfile = $testresults + resname + ".#{aname}.txt"
    starttime = Time.now
    #Add --sets cilout /dev/null to ignore CIL output.
    cmd = "#{$goblint} --conf #{$goblint_conf} -v --set dbg.timeout #{$timeout} #{aparam} #{filename} #{p.params} --enable dbg.uncalled --enable allglobs --enable printstats 1>#{outfile} 2>&1"
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
        `echo "TIMEOUT                    #{$timeout} s" >> #{outfile}`
      else
        puts "-- Failed!"
        `echo "EXITCODE                   #{status}" >> #{outfile}`
      end
    else
      system("#{$goblint} original/config.json --enable solverdiffs --compare_runs original increment #{filename} > #{outfile}.compare.txt") if $compare and not first
      puts "-- Done!"
    end
    first = false
    print_res p.id
    proc_linux_res(outfile, p.url, filename)
  end
  `rm -rf original increment` if $compare
end

#analysing the files
gname = ""
system("#{$goblint} --conf #{$goblint_conf} --writeconf #{$testresults}/conf.json")
$projects.each do |p|
  next if skipgrp.member? p.group
  next unless thegroup.nil? or p.group == thegroup
  next unless only.nil? or p.name == only
  if p.group != gname then
    gname = p.group
    puts gname
  end
  analyze_project(p, true)
  p.patches.each do |pfile|
    `patch -b #{p.path} #{pfile}`
    pp = Project.new(p.id,pfile,p.size,"generate!",nil,p.path,p.params,nil)
    analyze_project(pp, false)
    `patch -b -R #{p.path} #{pfile}`
    `rm #{p.path}.orig`
  end
end
print_res nil
puts ("Results: " + $theresultfile)
