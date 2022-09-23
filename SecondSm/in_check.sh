#!/bin/sh

while read len ; do
	echo $len | ./5_1
	echo "\n"
done <<END
	100 13
	1000 13
	10000 13
	100000 13
	1000000 13
END
