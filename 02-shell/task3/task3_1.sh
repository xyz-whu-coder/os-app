#!/bin/bash
#请添加以下代码，使用find命令在目录结构中搜索文件，并执行指定的操作，使用tee命令将输出保存在文件file_list
find ./ -size +50k -type f | tee file_list | wc -l