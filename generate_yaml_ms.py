# Generate asserts, as well as corresponding *.i, and *.yml files for sv-comp for the programs in bench/coreutils/.

# Execute with:
# python3 generate_yaml_ms.py
import os



def run_configuration(infile,outfile,uplevel,extraconf=""):
    goblint = uplevel + "/analyzer/goblint"

    if outfile == "":
        if infile.endswith(".c"):
            outfile = infile[:-2] + "_traces_rel.yml"
        else:
            raise ValueError("outfile must be specified for non-c files")

    cmd = goblint + " --conf " + uplevel + "/analyzer/conf/traces-rel.json " + extraconf +  " --set dbg.timeout 1200 --set ana.activated[+] apron --set ana.path_sens[+] threadflag --set ana.relation.privatization mutex-meet-tid-cluster12 --enable allglobs -v  --enable witness.yaml.enabled "

    # --set witness.yaml.path ./aget_comb_traces_rel.yml
    command = cmd + " " + infile + " --set witness.yaml.path  " + outfile
    print("Executing command: " + command)
    os.system(command)

# posix
os.chdir("/home/michael/Documents/goblint-cil/bench/pthread")
run_configuration("pfscan_comb.c pfscan_ftw.c","pfscan_comb_traces_rel.yml","../..")
run_configuration("aget_comb.c","aget_comb_traces_rel.yml","../..")
run_configuration("ctrace_comb.c","ctrace_comb_traces_rel.yml","../..")
run_configuration("knot_comb.c","knot_comb_traces_rel.yml","../..")
run_configuration("ypbind_comb.c","ypbind_comb_traces_rel.yml","../..")
run_configuration("smptprc_comb.c","smptprc_comb_traces_rel.yml","../..")

# svcomp
os.chdir("/home/michael/Documents/goblint-cil/bench/svcomp")
run_configuration("linux-3.14--drivers--usb--misc--iowarrior.ko.cil.i","linux-3.14--drivers--usb--misc--iowarrior.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--usb--misc--adutux.ko.cil.i","linux-3.14--drivers--usb--misc--adutux.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--net--irda--w83977af_ir.ko.cil.i","linux-3.14--drivers--net--irda--w83977af_ir.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--spi--spi-tegra20-slink.ko.cil.i","linux-3.14--drivers--spi--spi-tegra20-slink.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--net--irda--nsc-ircc.ko.cil.i","linux-3.14--drivers--net--irda--nsc-ircc.ko.cil_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-1.i","linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-1_traces_rel.yml","../..","--enable ana.sv-comp.functions")
run_configuration("linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-2.i","linux-3.14--drivers--media--platform--marvell-ccic--cafe_ccic.ko.cil-2_traces_rel.yml","../..","--enable ana.sv-comp.functions")

# concrat
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/brubeck")
run_configuration("brubeck.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/C-Thread-Pool")
run_configuration("cThreadPool.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/cava")
run_configuration("cava.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/dump1090")
run_configuration("dump1090.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/EasyLogger")
run_configuration("easyLogger.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/fzy")
run_configuration("fzy.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/klib")
run_configuration("klib.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/level-ip")
run_configuration("level-ip.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/libaco")
run_configuration("libaco.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/libfaketime")
run_configuration("libfaketime.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/libfreenect")
run_configuration("libfreenect.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/pingfs")
run_configuration("pingfs.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/snoopy")
run_configuration("snoopy.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/uthash")
run_configuration("uthash.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/vanitygen")
run_configuration("vanitygen.c","","../../..")
os.chdir("/home/michael/Documents/goblint-cil/bench/concrat/wrk")
run_configuration("wrk.c","","../../..")
