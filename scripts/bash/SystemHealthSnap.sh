#!/bin/bash

echo -e "$(date)\t\t$(hostname)\t$(whoami)\t\t$(df --output=avail -B 1 "$PWD" | tail -n 1) B /  $(df -B 1 --output=size / | tail -1) B"
