#!/bin/bash

# set -x

OLDSTRING=$1
NEWSTRING=$2
FILE=$3

sed "s|$OLDSTRING|$NEWSTRING|g" $FILE > tempfile 
touch -r $FILE tempfile
mv tempfile $FILE
