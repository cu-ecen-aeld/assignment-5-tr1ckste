#!/bin/bash
if [ $# != 2 ]; then
    echo "2 parameters expected"
    exit 1
fi
filesdir=$1
searchstr=$2
if [ ! -d $filesdir ]; then
    echo "$filesdir is not a directory"
    exit 1
fi

linesNumber=$(grep -r $searchstr $filesdir | wc -l)
filesNumber=$(grep -lr $searchstr $filesdir | wc -l)
echo "The number of files are $filesNumber and the number of matching lines are $linesNumber"
exit 0