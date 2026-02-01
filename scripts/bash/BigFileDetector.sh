#!/bin/bash

FILE=$1
MAX=1048576

if [ -f "$FILE" ]; then
	if find "$FILE" -maxdepth 0 -size -"${MAX}"c | grep -q .; then
   		 echo "File size is within limits."
	else
    		echo "Warning: File size is too large"
	fi
else
	echo "File does not exist"
fi
