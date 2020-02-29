#!/bin/bash
recursion () {
	path=$1
	for obj in ls $path
	do
		if [[ -d $obj ]]
		then recursion $obj; fi;
	done
	for obj in find $path -name "*.$ext"
	do 
		cp $obj ${bac}/`basename obj`$count".$ext"
	       	((count+=1)) 
	done
}
#directory extention backup archive
dir=$1; ext=$2; bac=$3; arc=$4
if [[ ! -e $bac ]]
then mkdir $bac; fi;
count=0
recursion $dir
tar -zcf $arc $bac
echo done
