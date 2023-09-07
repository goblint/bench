#!/bin/bash
set -xe

pandoc README.md -o README.pdf

zip -r unassume.zip \
    README.md \
    README.pdf \
    LICENSE \
    unassume.ova \
    results/
