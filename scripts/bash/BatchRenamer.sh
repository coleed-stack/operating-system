#!/bin/bash
DIR=~/Documents/CS380/BashFiles/TextFiles/

for file in ~/Documents/CS380/BashFiles/TextFiles/*; do
	filename=$(basename "$file")
	mv "$file" "$DIR/OLD_$filename"
done
