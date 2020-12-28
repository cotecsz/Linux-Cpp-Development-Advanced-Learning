# Linux 命令速查手册（一）帮助命令

[TOC]

## 1 帮助命令

### 1.1 whatis：简述命令的作用

whatis： 简述命令的作用

```bash
root@Eternal:~# whatis whatis
whatis (1)           - display one-line manual page descriptions
```

### 1.2 info：查看命令详细的说明文档

```bash
root@Eternal:~# info whatis
WHATIS(1)                     Manual pager utils                     WHATIS(1)

NAME
       whatis - display one-line manual page descriptions

SYNOPSIS
       whatis  [-dlv?V]  [-r|-w]  [-s  list]  [-m  system[,...]] [-M path] [-L
       locale] [-C file] name ...

DESCRIPTION
       Each manual page has a short description available within  it.   whatis
       searches  the  manual  page names and displays the manual page descrip‐
       tions of any name matched.

       name may contain wildcards (-w) or be a regular expression (-r).  Using
       these  options, it may be necessary to quote the name or escape (\) the
       special characters to stop the shell from interpreting them.
       ......
```

### 1.3 man：查看命令的说明文档

```bash
root@Eternal:~# man locate
locate(1)                   General Commands Manual                  locate(1)

NAME
       locate - find files by name

SYNOPSIS
       locate [OPTION]... PATTERN...

DESCRIPTION
       locate  reads  one or more databases prepared by updatedb(8) and writes
       file names matching at least one of the PATTERNs  to  standard  output,
       one per line.

       If  --regex is not specified, PATTERNs can contain globbing characters.
       If any PATTERN contains no globbing characters, locate  behaves  as  if
       the pattern were *PATTERN*.

       By default, locate does not check whether files found in database still
       exist (but it does require all parent directories to exist if the data‐
       base  was built with --require-visibility no).  locate can never report
       files created after the most recent update of the relevant database.
       ......
```

man分类标示：

1）用户可以操作的命令或者是可执行文件 

2)）系统核心可调用的函数与工具等 

3)）一些常用的函数与数据库 

4）设备文件的说明 

5）设置文件或者某些文件的格式 

6）游戏 

7）惯例与协议等。例如Linux标准文件系统、网络协议、ASCⅡ，码等说明内容 

8）系统管理员可用的管理条令 

9）与内核有关的文件

用法：

```bash
root@Eternal:~# man 3 printf
```



### 1.4 which：查看可执行文件的路径

which：查看可执行文件的路径

```bash
root@Eternal:~# which locate
/usr/bin/locate
```

### 1.5 whereis：查看程序的搜索路径

whereis：查看程序的搜索路径

```bash
root@Eternal:~# whereis locate
locate: /usr/bin/locate /usr/share/man/man1/locate.1.gz
```

