#!/bin/bash
if [ $# != 2 ]; then
    echo "2 parameters expected"
    exit 1
fi
writefile=$1
writestr=$2
mkdir -p "$(dirname $writefile)" && touch "$writefile"
echo $writestr > $writefile
exit 0