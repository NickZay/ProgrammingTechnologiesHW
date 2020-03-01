#!/bin/bash
#directory extention backup archive
dir=$1; ext=$2; bac=$3; arc=$4
if [[ ! -e $bac ]]
then mkdir $bac; fi;
count=0
for obj in `find $dir -name "*.$ext"`
do
	cp $obj ${bac}/$count`basename $obj`
       	((count+=1)) 
done
tar -zcf $arc $bac
echo done
