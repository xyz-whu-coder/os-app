#!/bin/bash
echo "please enter two number"
read a
read b
#请添加代码，判断a,b是否相等
# if [...]
if [ $a -eq $b ]; 
then echo "NO.1=NO.2"
#请添加代码，判断a,b是否相等
# elif [...]
elif [ $a -gt $b ]; 
then echo "NO.1 > NO.2"
else echo "NO.1 < No.2"
fi

