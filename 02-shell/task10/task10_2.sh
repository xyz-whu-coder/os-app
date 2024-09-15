#!/bin/bash
if [ $# -ne 2 ]
then
	echo "$0 match_text filename"
	exit 1
fi
match_text=$1
filename=$2

#请添加代码，利用grep指令测试文件是否包含特定的文本内容
grep -q "$match_text" $filename

if [ $? -eq 0 ]
then 
	echo "The text exists in the file"
else
	echo "Text does not exist in the file"
fi

