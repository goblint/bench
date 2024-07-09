# Generate asserts, as well as corresponding *.i, and *.yml files for sv-comp for the programs in bench/coreutils/.

# Execute with:
# python3 generate_yaml_ms.py
import os
from multiprocessing import Pool

def run_configuration(cwd,infile,outfile,uplevel,extraconf=""):
    os.chdir(cwd)
    goblint = uplevel + "/analyzer/goblint"

    if outfile == "":
        if infile.endswith(".c"):
            outfile = infile[:-2] + "_traces_rel.yml"
        else:
            raise ValueError("outfile must be specified for non-c files")

    cmd = goblint + "--enable pre.keep --conf " + uplevel + "/analyzer/conf/traces-rel.json " + extraconf +  " --set dbg.timeout 1200 --set ana.activated[+] apron --set ana.path_sens[+] threadflag --set ana.relation.privatization mutex-meet-tid-cluster12 --enable allglobs -v  --enable witness.yaml.enabled "

    # --set witness.yaml.path ./aget_comb_traces_rel.yml
    command = cmd + " " + infile + " --set witness.yaml.path  " + outfile
    print("Executing command: " + command)
    os.system(command)

bench_dir = "/home/goblint/michael-schwarz-dissertation/bench/"
posix_dir = bench_dir + "pthread"
svcomp_dir = bench_dir + "svcomp"
concrat_dir = bench_dir + "concrat/"
tasks = [
    (posix_dir,"pfscan_comb.c pfscan_ftw.c","pfscan_comb_traces_rel.yml","../.."),
    (posix_dir,"aget_comb.c","aget_comb_traces_rel.yml","../.."),
    (posix_dir,"ctrace_comb.c","ctrace_comb_traces_rel.yml","../.."),
    (posix_dir,"knot_comb.c","knot_comb_traces_rel.yml","../.."),
    (posix_dir,"ypbind_comb.c","ypbind_comb_traces_rel.yml","../.."),
    (posix_dir,"smptprc_comb.c","smptprc_comb_traces_rel.yml","../.."),
    (svcomp_dir,"linux-3.14--drivers--usb--misc--iowarrior.ko.cil.i","linux-3.14--drivers--usb--misc--iowarrior.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--usb--misc--adutux.ko.cil.i","linux-3.14--drivers--usb--misc--adutux.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--net--irda--w83977af_ir.ko.cil.i","linux-3.14--drivers--net--irda--w83977af_ir.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--spi--spi-tegra20-slink.ko.cil.i","linux-3.14--drivers--spi--spi-tegra20-slink.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--net--irda--nsc-ircc.ko.cil.i","linux-3.14--drivers--net--irda--nsc-ircc.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-1.i","linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-1_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (svcomp_dir,"linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-2.i","linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-2_traces_rel.yml","../..","--enable ana.sv-comp.functions"),
    (concrat_dir + "brubeck","brubeck.c","","../../.."),
    (concrat_dir + "C-Thread-Pool","cThreadPool.c","","../../.."),
    (concrat_dir + "cava","cava.c","","../../.."),
    (concrat_dir + "dump1090","dump1090.c","","../../.."),
    (concrat_dir + "EasyLogger","easyLogger.c","","../../.."),
    (concrat_dir + "fzy","fzy.c","","../../.."),
    (concrat_dir + "klib","klib.c","","../../.."),
    (concrat_dir + "level-ip","level-ip.c","","../../.."),
    (concrat_dir + "libaco","libaco.c","","../../.."),
    (concrat_dir + "libfaketime","libfaketime.c","","../../.."),
    (concrat_dir + "libfreenect","libfreenect.c","","../../.."),
    (concrat_dir + "pingfs","pingfs.c","","../../.."),
    (concrat_dir + "snoopy","snoopy.c","","../../.."),
    (concrat_dir + "uthash","uthash.c","","../../.."),
    (concrat_dir + "vanitygen","vanitygen.c","","../../.."),
    (concrat_dir + "wrk","wrk.c","","../../..")
]

def really_run_configuration(task):
    run_configuration(*task)

if __name__ == '__main__':
    with Pool(10) as p:
        p.map(really_run_configuration, tasks)
