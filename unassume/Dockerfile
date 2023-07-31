FROM ocaml/opam:ubuntu-22.04-opam
# make opam 2.1 default for make setup
RUN sudo ln -sf /usr/bin/opam-2.1 /usr/bin/opam

RUN sudo apt-get update \
    && sudo apt-get install -y libgmp-dev libmpfr-dev pkg-config autoconf gcc-multilib \
    && sudo apt-get install -y wget software-properties-common \
    && sudo apt-get install -y openjdk-11-jre-headless \
    && sudo add-apt-repository ppa:sosy-lab/benchmarking \
    && sudo apt-get install -y benchexec

# update local opam repository because base image may be outdated
RUN cd /home/opam/opam-repository \
    && git pull origin master \
    && opam update -y

RUN wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/-/raw/main/2023/cpachecker.zip && \
    unzip cpachecker.zip && \
    rm cpachecker.zip

RUN wget https://gitlab.com/sosy-lab/sv-comp/archives-2023/-/raw/main/2023/uautomizer.zip && \
    unzip uautomizer.zip && \
    rm uautomizer.zip 

RUN git clone https://github.com/goblint/analyzer.git goblint && \
    cd goblint && \
    make setup && \
    make

RUN mkdir results

COPY --chown=opam eval-prec /home/opam/eval-prec
