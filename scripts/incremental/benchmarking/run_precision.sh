#!/bin/bash
ANALYZER_DIR=$1

#Number of cores to be used
NCORES=$2

echo "Starting run on figlet"
python3 precision.py $ANALYZER_DIR figlet $NCORES
mv result_precision result_precision_figlet

echo "Starting run on zstd"
python3 precision.py $ANALYZER_DIR zstd $NCORES
mv result_precision result_precision_zstd

echo "Starting run on chrony"
python3 precision.py $ANALYZER_DIR chrony $NCORES
mv result_precision result_precision_chrony
