#!/usr/bin/ruby
require 'fileutils'
require 'yaml'
Dir.chdir(File.dirname(__FILE__))
$goblint = File.expand_path('../analyzer/goblint')
$messagesCompare = File.expand_path('../analyzer/_build/default/src/messagesCompare.exe')
fail 'Please run script from goblint dir!' unless File.exist?($goblint)
$goblint_version = `#{$goblint} --version`
$bench_version = `git describe --all --long --dirty 2> /dev/null`
results = 'bench_result'
Dir.mkdir(results) unless Dir.exist?(results)
$testresults = File.expand_path('bench_result') + '/'
$bench_path = File.expand_path('.') + '/'
$repo_url = 'https://github.com/goblint/bench/blob/master/'

class Project
  attr_reader :id, :name, :group
  attr_accessor :info, :params, :url
  def initialize(id, name, info, group, params)
    @id       = id
    @name     = name
    @info     = info
    @group    = group
    @params   = params
  end
  def url
    $repo_url
  end
  def to_html
    name = "<div title=\"#{@info}\"><a href=\"#{url}\">#{@name}</a></div>"
    "<td>#{@id}</td><td>#{name}</td>\n" + "\n"
  end
  def to_s
    @name.to_s
  end
end


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
$theresultfile = File.join($testresults, 'index.html')

def print_file_res (f, name)
  first = true
  $analyses.each do |a|
    aname = a[0]
    outfile = name + ".#{aname}.txt"
    if File.exists?($testresults + outfile)
      File.open($testresults + outfile, 'r') do |g|
        lines = g.readlines
        vars, evals = lines.grep(/vars = (\d*).*evals = (\d+)/) { |x| [$1.to_i, $2.to_i] } .first
        res = lines.grep(/^TIMEOUT\s*(.*) s.*$/) { |x| $1 }
        if res == []
          dur = lines.grep(/^Duration: (.*) s/) { |x| $1 }
          cod = lines.grep(/^EXITCODE\s*(.*)$/) { |x| $1 }
          if cod == [] and not dur == []
            if $compare
              unless first
                compfile = "#{outfile}.compare.txt"
                complines = File.readlines($testresults + compfile)
                verdict = complines.grep(/comparison summary: original (.*) increment/) { |x| $1 }.first
                msg = case verdict
                  when 'equal to' then '='
                  when 'more precise than' then '⊑'
                  when 'incomparable to' then '≸'
                  when 'less precise than' then '⊒'
                end
                thenumbers = "<a href=\"#{compfile}\">#{msg} </a>"
                thenumbers << " <a href=\"#{outfile}.compare.messages.txt\">M</a>"
              end
            else
              safely = lines.grep(/\[Success\]\[Behavior > Undefined > ArrayOutOfBound/).size
              vulner = lines.grep(/\[Warning\]\[Behavior > Undefined > ArrayOutOfBound/).size
              unsafe = lines.grep(/\[Error\]\[Behavior > Undefined > ArrayOutOfBound/).size
              total = lines.grep(/\[Behavior > Undefined > ArrayOutOfBounds/).size
              uncalled = lines.grep(/will never be called/).reject {|x| x =~ /__check/}.size
              deadlock = lines.grep(/\[Deadlock\]/).size
              thenumbers =  "<font color=\"green\">#{safely}</font>+"
              thenumbers << "<font color=\"orange\">#{vulner}</font>+"
              thenumbers << "<font color=\"red\">#{unsafe}</font>="
              thenumbers << "#{total}"
              thenumbers << "; <font color=\"blue\">#{deadlock}</font>"
              thenumbers << "; <font color=\"magenta\">#{uncalled}</font>" if uncalled > 0
            end
            thenumbers = " (#{thenumbers})" unless thenumbers.nil?
            f.puts "<td><a href=\"#{outfile}.html\">#{"%.2f" % dur} s / #{vars} vars / #{evals} evals</a>#{thenumbers}</td>"
          else
            f.puts "<td><a href=\"#{outfile}.html\">failed (code: #{cod.first.to_s})</a></td>"
          end
        else
    f.puts "<td><a href=\"#{outfile}.html\">#{res.first.to_s} s</a> (limit)</td>"
        end
      end
    else
      f.puts '<td>N/A</a></td>'
    end
  first = false
  end
end

def print_res (i)
  File.open($theresultfile, 'w') do |f|
    f.puts $header
    f.puts '<body>'
    f.puts "<p>Benchmarking in progress: #{i}/#{$projects.length} <progress value=\"#{i}\" max=\"#{$projects.length}\" /></p>" unless i.nil?
    f.puts '<table border=2 cellpadding=4 style="font-size: 90%">'
    gname = ''
    $projects.each do |p|
      if p.group != gname
        gname = p.group
        f.puts "<tr><th colspan=#{3+$analyses.size}>#{gname}</th></tr>"
        f.puts '<tr><th>#</th><th>Name</th>'
        $analyses.each do |a|
          aname = a[0]
          f.puts "<th>#{aname}</th>"
        end
      end
      f.puts '<tr>'
      f.puts p.to_html
      print_file_res(f, p.name)
      f.puts '</tr>'
    end
    f.puts '</table>'
    f.print '<p style="font-size: 80%; white-space: pre-line">'
    f.puts "Last updated: #{Time.now.strftime("%Y-%m-%d %H:%M:%S %z")}"
    f.puts "Bench version: #{$bench_version}"
    f.puts "#{$goblint_version}"
    f.puts "Goblint base configuration: <a href=\"#{$goblint_conf_name}\">#{$goblint_conf_name}</a>."
    f.puts "Analysis definitions: <a href=\"#{$conf_name}\">#{$conf_name}</a>."
    f.puts '</p>'
    f.puts '</body>'
    f.puts '</html>'
  end
end

#Command line parameters

if ARGV[2].nil?
  puts 'You must run command with timout, conf, and at least one benchmark set, e.g.:'
  puts './update_bench_incremental.rb 60 index/defs/incremental.yaml index/sets/posix.yaml'
  exit 1
end

$timeout = ARGV[0].to_i
conf_file = ARGV[1]
groups = ARGV[2..-1]

#processing the input file

$analyses = []
conf = YAML.load_file(conf_file)
$conf_name = File.basename(conf_file)
$goblint_conf = File.expand_path(conf['baseconf'])
$goblint_conf_name = File.basename($goblint_conf)
abort("Configuration lacks base conf: #{$goblint_conf}") unless File.exist?($goblint_conf)

$compare = conf['compare']
$incremental = conf['incremental']

conf.delete('compare')
conf.delete('baseconf')
conf.delete('incremental')
conf.each { |(key, value)| $analyses << [key, value.nil? ? '' : value] }

id = 0
groups.each do |group|
  benchmarks = YAML.load_file(group)
  gname = File.basename(group, '.yaml').upcase
  #TODO: name is ignored because it breaks patch hacks.
  benchmarks.each do |name, spec|
    info = spec['info']
    params = spec['param']
    params = '' if params.nil?
    id += 1
    $projects << Project.new(id,name,info,gname,params)
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


def proc_res(resultfile, url)
  File.open(resultfile, 'r') do |f|
    File.open(resultfile + '.html', 'w') do |o|
      o.puts $fileheader
      while (line = f.gets)
        if line =~ /race with|\[Warning\]/
          o.puts '<font color="red">' + line.chop + '</font>'
        elsif line =~ /\[Success\]/
          o.puts '<font color="green">' + line.chop + '</font>'
        else
          o.puts line
        end
      end
      o.puts '</body>'
      o.puts '</html>'
    end
  end
end

$rootdirname = File.expand_path("./ddverify/")
$maxlen = $analyses.map { |x| x[0].length }.max + 1
def analyze_project(p, save)
  dirname = $rootdirname
  resname = p.name
  Dir.chdir(dirname)
  puts "Analysing #{resname} (#{p.id}/#{$projects.length})"
  first = true
  $analyses.each do |a|
    aname = a[0]
    aparam = a[1]
    if first
      aparam += ' --enable incremental.save ' if save
      aparam += ' --enable incremental.only-rename ' if $incremental and not save
      aparam += ' --set save_run original ' if $compare
      aparam += ' --set outfile original.messages.json ' if $compare
    else
      aparam += ' --enable incremental.load ' if $incremental
      aparam += ' --set save_run increment ' if $compare
      aparam += ' --set outfile increment.messages.json ' if $compare
    end
    print "  #{format("%*s", -$maxlen, aname)}"
    STDOUT.flush
    outfile = $testresults + resname + ".#{aname}.txt"
    starttime = Time.now
    #Add --sets cilout /dev/null to ignore CIL output.
    cmd = "#{$goblint} --conf #{$goblint_conf} -v --set dbg.timeout #{$timeout} #{aparam} #{p.params} --enable dbg.uncalled --enable allglobs --enable printstats --set result json-messages 1>#{outfile} 2>&1"
    system(cmd)
    status = $?.exitstatus
    endtime   = Time.now
    File.open(outfile, 'a') do |f|
      f.puts "\n=== APPENDED BY BENCHMARKING SCRIPT ==="
      f.puts "Analysis began: #{starttime}"
      f.puts "Analysis ended: #{endtime}"
      f.puts "Duration: #{format("%.02f", endtime-starttime)} s"
      f.puts "Goblint params: #{cmd}"
      f.puts $vrsn
    end
    if status != 0
      if status == 124
        puts '-- Timeout!'
        `echo "TIMEOUT                    #{$timeout} s" >> #{outfile}`
      else
        puts '-- Failed!'
        `echo "EXITCODE                   #{status}" >> #{outfile}`
      end
    else
      system("#{$goblint} --conf #{$goblint_conf} -v --enable dbg.compare_runs.diff --compare_runs original increment #{p.params} 2>&1 | sed '2000,/comparison summary/{/comparison summary/!d;}' > #{outfile}.compare.txt") if $compare and not first
      system("#{$messagesCompare} --no-colors original.messages.json increment.messages.json > #{outfile}.compare.messages.txt") if $compare and not first
      puts '-- Done!'
    end
    first = false
    print_res p.id
    proc_res(outfile, p.url)
  end
  `rm -rf original increment` if $compare
  `rm original.messages.json increment.messages.json` if $compare
end

#analysing the files
gname = ''
system("rm -f #{$testresults}/*")
FileUtils.cp(conf_file, File.join($testresults, $conf_name))
system("#{$goblint} --conf #{$goblint_conf} --writeconf #{$testresults}/#{$goblint_conf_name}")
$projects.each do |p|
  if p.group != gname
    gname = p.group
    puts gname
  end
  analyze_project(p, $incremental)
  `rm -rf incremental_data`
end
print_res nil
puts ('Results: ' + $theresultfile)
