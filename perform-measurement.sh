# Chris Ong CSE 374 HW3 Part 2 4/26/21

#!/bin/bash

if [ $# == 0 ]; then
   echo "Error, you must pass in 1 argument, not 0"
   exit 1
fi

TEMPFILE=$(mktemp 2> /dev/null)

wget -o /dev/null -O "$TEMPFILE" $1 || { echo 0; rm "$TEMPFILE" > /dev/null 2>&1; exit 1; }

wc -c < "$TEMPFILE"

exit 0