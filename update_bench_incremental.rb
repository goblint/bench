#!/usr/bin/ruby
require 'fileutils'
require 'yaml'
Dir.chdir(File.dirname(__FILE__))
$goblint = File.expand_path('../analyzer/goblint')
fail 'Please run script from goblint dir!' unless File.exist?($goblint)
$goblint_version = `#{$goblint} --version`
$bench_version = `git describe --all --long --dirty 2> /dev/null`
results = 'bench_result'
Dir.mkdir(results) unless Dir.exist?(results)
$testresults = File.expand_path('bench_result') + '/'
$bench_path = File.expand_path('.') + '/'
$repo_url = 'https://github.com/goblint/bench/blob/master/'

class Project
  attr_reader :id, :name, :group, :path, :patches, :size
  attr_accessor :info, :params, :url
  def initialize(id, name, size, info, group, path, params, patches)
    @id       = id
    @name     = name
    @size     = size
    @info     = info
    @group    = group
    @path     = path
    @params   = params
    @patches  = patches
  end
  def url
    $repo_url + @path
  end
  def to_html
    name = "<div title=\"#{@info}\"><a href=\"#{url}\">#{@name}</a></div>"
    "<td>#{@id}</td><td>#{name}</td>\n" + "<td>#{@size}</td>\n"
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

def print_file_res (f, path)
  first = true
  $analyses.each do |a|
    aname = a[0]
    outfile = File.basename(path,'.c') + ".#{aname}.txt"
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
                verdict = complines.grep(/^Comparison summary: original (.*) increment/) { |x| $1 }.first
                msg = case verdict
                  when 'equal to' then '='
                  when 'more precise than' then '⊑'
                  when 'incomparable to' then '≸'
                  when 'less precise than' then '⊒'
                end
                thenumbers = "<a href=\"#{compfile}\">#{msg}</a>"
              end
            else
              safely = lines.grep(/[^n]safe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              vulner = lines.grep(/vulnerable:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              unsafe = lines.grep(/unsafe:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              total = lines.grep(/total:[ ]*([0-9]*)/) { |x| $1.to_i } .first
              uncalled = lines.grep(/will never be called/).reject {|x| x =~ /__check/}.size
              thenumbers =  "<font color=\"green\">#{safely}</font>+"
              thenumbers << "<font color=\"orange\">#{vulner}</font>+"
              thenumbers << "<font color=\"red\">#{unsafe}</font>="
              thenumbers << "#{total}"
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
        f.puts '<tr><th>#</th><th>Name</th><th>Size</th>'
        $analyses.each do |a|
          aname = a[0]
          f.puts "<th>#{aname}</th>"
        end
      end
      f.puts '<tr>'
      f.puts p.to_html
      print_file_res(f, p.path)
      f.puts '</tr>'
      p.patches.each do |pfile|
        f.puts '<tr>'
        pname = File.basename(pfile)
        `cp #{pfile} #{$testresults + pname}`
        f.puts "<td>-</td><td><a href=\"#{pname}\">#{pname}</a></td>\n" + "<td><a href=\"#{pname}.html\">patched</a></td>\n"
        print_file_res(f, pfile)
        f.puts '</tr>'
      end
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
    path = spec['path']
    params = spec['params']
    params = '' if params.nil?
    fullpath = File.expand_path(path, $bench_path)
    size = "#{`wc -l #{path}`.split[0]} lines"
    patches = $incremental ? Dir["#{fullpath.chomp('.c')}*.patch"] : []
    name = File.basename(path, '.c')
    id += 1
    $projects << Project.new(id,name,size,info,gname,path,params,patches.sort)
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


def proc_res(resultfile, url, filename)
  File.open(resultfile, 'r') do |f|
    File.open(resultfile + '.html', 'w') do |o|
      o.puts $fileheader
      while (line = f.gets)
        line.gsub!(/(#{filename}:(\d+))/, "<a href=\" #{url}#L\\2\">\\1</a>")
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


$maxlen = $analyses.map { |x| x[0].length }.max + 1
def analyze_project(p, save)
  filepath = File.expand_path(p.path, $bench_path)
  dirname = File.dirname(filepath)
  filename = File.basename(filepath)
  resname = File.basename(p.name,'.c')
  Dir.chdir(dirname)
  puts "Analysing #{resname} (#{p.id}/#{$projects.length})"
  first = true
  $analyses.each do |a|
    aname = a[0]
    aparam = a[1]
    if first
      aparam += ' --enable incremental.save ' if save
      aparam += ' --enable incremental.only-rename ' unless save
      aparam += ' --set save_run original ' if $compare
    else
      aparam += ' --enable incremental.load ' if $incremental
      aparam += ' --set save_run increment ' if $compare
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
      system("#{$goblint} --conf #{$goblint_conf} -v --disable dbg.compare_runs.glob --enable solverdiffs --compare_runs original increment #{filename} #{p.params} 2>&1 | sed '2000,/Comparison summary/{/Comparison summary/!d;}' > #{outfile}.compare.txt") if $compare and not first
      puts '-- Done!'
    end
    first = false
    print_res p.id
    proc_res(outfile, p.url, filename)
  end
  `rm -rf original increment` if $compare
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
  analyze_project(p, true)
  path = File.expand_path(p.path, $bench_path)
  p.patches.each do |pfile|
    `patch -b #{path} #{pfile}`
    pp = Project.new(p.id,pfile,p.size,'patch',nil,path,p.params,nil)
    analyze_project(pp, false)
    `patch -b -R #{path} #{pfile}`
    `rm #{path}.orig`
  end
  `rm -rf incremental_data`
end
print_res nil
puts ('Results: ' + $theresultfile)
