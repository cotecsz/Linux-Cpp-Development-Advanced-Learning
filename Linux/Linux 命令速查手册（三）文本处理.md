# Linux 命令速查手册（三）文本处理

[TOC]

## 3 文本处理

### 3.1 find：文件查找

- find . -name "file_name" -maxdepth n：在当前目录下搜索n层，查找 `file_name` 文件

```bash
root@Eternal:/home/sigai# find . -name "new*" 
./new_dir
./new_dir/new_file
root@Eternal:/home/sigai# find . -maxdepth 1 -name "new*" 
./new_dir
root@Eternal:/home/sigai# find . -maxdepth 1 -name "new*" -type f
root@Eternal:/home/sigai# find . -maxdepth 2 -name "new*" -type f
./new_dir/new_file
root@Eternal:/home/sigai# 
```

- find [dir_name] -name [file_name] ：在 `dir_name` 下查找 `file_name` 文件

```bash
root@Eternal:~# find -name "*.txt" -o -name "*.pdf"
./Programfile/miniconda/share/doc/xz/faq.txt
./Programfile/miniconda/share/doc/xz/xz-file-format.txt
./Programfile/miniconda/share/doc/xz/history.txt
./Programfile/miniconda/share/doc/xz/examples/00_README.txt
./Programfile/miniconda/share/doc/xz/lzma-file-format.txt
...
root@Eternal:~# find . \( -name "*.txt" -o -name "*.pdf" \)
./Programfile/miniconda/share/doc/xz/faq.txt
./Programfile/miniconda/share/doc/xz/xz-file-format.txt
./Programfile/miniconda/share/doc/xz/history.txt
./Programfile/miniconda/share/doc/xz/examples/00_README.txt
./Programfile/miniconda/share/doc/xz/lzma-file-format.txt
......
```

- find [dir_name] -path [path_name]：在 `dir_name` 目录下，查找包含 `path_name` 的路径

```bash
root@Eternal:~# find /home -path "*new_dir"
/home/sigai/new_dir
/home/new_dir
root@Eternal:~# find /home -path "*new_dir*"
/home/sigai/new_dir
/home/sigai/new_dir/new_file
/home/new_dir
/home/new_dir/old_file
root@Eternal:~# find / -path "*new_dir*"
/home/sigai/new_dir
/home/sigai/new_dir/new_file
/home/new_dir
/home/new_dir/old_file
/new_dir
/new_dir/new_file
```



### 3.2 grep：文本搜索

- grep match_pattern file：默认访问匹配
  - -o 只输出匹配的文本行 **VS** -v 只输出没有匹配的文本行
  - -c 统计文件中包含文本的次数

- grep -c “text” filename
  - -n 打印匹配的行号
  - -i 搜索时忽略大小写
  - -l 只打印文件名

- grep "content" . -R -n：在多级目录中对文本递归搜索

```bash

root@Eternal:/home/sigai# grep "file" . -R -n
./.bashrc:2:# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
./.bashrc:15:# append to the history file, don't overwrite it
./.bashrc:27:# match all files and zero or more directories and subdirectories.
./.bashrc:30:# make less more friendly for non-text input files, see lesspipe(1)
./.bashrc:100:# You may want to put all your additions into a separate file like
./.bashrc:109:# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
./.bash_history:9:chmod new_dir/new_file 
./.bash_history:10:chmod 777 new_dir/new_file 
./.bash_history:14:ln new_dir/new_file soft_link_new
./.bash_history:16:chmod a+x new_dir/new_file 
./.profile:1:# ~/.profile: executed by the command interpreter for login shells.
./.profile:2:# This file is not read by bash(1), if ~/.bash_profile or ~/.bash_login
./.profile:4:# see /usr/share/doc/bash/examples/startup-files for examples.
./.profile:5:# the files are located in the bash-doc package.
./.profile:7:# the default umask is set in /etc/profile; for setting the umask
./new_dir/new_file:1:This is a new file.
root@Eternal:/home/sigai# grep -e "file" -e "old" new_dir/new_file 
This is a new file.
```



### 3.3 xargs：命令行参数转换

- cat file_name | xargs -n 3：单行输出转换为多行输出

```bash
root@Eternal:/home/sigai# grep -e "file" -e "old" new_dir/new_file 
This is a new file.
root@Eternal:/home/sigai# cat new_dir/new_file  | xargs -n 3
This is a
new file.
root@Eternal:/home/sigai#
```



### 3.4 sort：排序

字段说明

- -n 按数字进行排序 VS -d 按字典序进行排序
- -r 逆序排序
- -k N 指定按第N列排序

```bash
root@Eternal:/home/sigai# sort -nrk 1 new_dir/new_file 
This is a new file.
```



### 3.5 uniq：消除重复行

- sort file_name | uniq
  - 消除重复行
  - -c 统计各行在文件中重复的次数
  - -d 找出重复行

```bash
root@Eternal:/home/sigai# sort new_dir/new_file | uniq
  Add a new lines.
  The Third line.
  This is a new file.
root@Eternal:/home/sigai# sort new_dir/new_file | uniq -c
      1   Add a new lines.
      2   The Third line.
      1   This is a new file.
root@Eternal:/home/sigai# sort new_dir/new_file | uniq -d
  The Third line.
```



### 3.6 cut：按列切分字符

- cut -f1,3 file_name：截取文件 `file_name` 的第2行和第4行
- cut -f2 file_name：删除文件 `file_name` 的第2行
- cut  f2 -d ":" file_name：指定定界符



### 3.7 paste：按列拼接文本

- paste -d ":" file_1 file_2 ：将两个文件拼接，以":" 分割

```bash
root@Eternal:/home/sigai/new_dir# paste -d ":" new_file table.txt > paste_file
root@Eternal:/home/sigai/new_dir# cat paste_file 
  This is a new file.:01 tom 69 91
  Add a new lines.:02 jack 71 87
  The Third line.:03 alex 68 98
  The Third line.:
```



### 3.8 wc：统计行和字符数

- wc
  - -l：统计行数
  - -w：统计单词数
  - -c：统计字符数

```bash
root@Eternal:/home/sigai/new_dir# cat paste_file | wc -l
4
root@Eternal:/home/sigai/new_dir# cat paste_file | wc -w
24
root@Eternal:/home/sigai/new_dir# cat paste_file | wc -c
119
```



### 3.9 sed：文本替换

- sed 's/text/replace_txt/' file：将文件 `file` 中 `text` 替换为 `replace_txt`

```bash
root@Eternal:/home/sigai/new_dir# cat new_file 
  This is a new file.
  Add a new lines.
  The Third line.
  The Third line.
root@Eternal:/home/sigai/new_dir# sed 's/lines/line/' new_file 
  This is a new file.
  Add a new line.
  The Third line.
  The Third line.
```

具体用法：https://man.linuxde.net/sed



### awk：数据流处理

用法：https://man.linuxde.net/awk

