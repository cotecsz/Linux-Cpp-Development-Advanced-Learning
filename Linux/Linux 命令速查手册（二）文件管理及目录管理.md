# Linux 命令速查手册（二）文件管理及目录管理

[TOC]

## 2 文件及目录管理

### 2.1 mkdir：创建目录

创建目录：mkdir new_dir

```bash
root@Eternal:/home/sigai# mkdir new_dir
root@Eternal:/home/sigai# ls
new_dir
```

### 2.2 rm：删除文件/ 目录

- 删除文件/空目录：rm file/directory

- 删除包含文件或文件夹的目录：rm -rf directory
- 删除日志文件：rm *log

```bash
root@Eternal:/home/sigai# cd new_dir/
root@Eternal:/home/sigai/new_dir# vim new_file
root@Eternal:/home/sigai/new_dir# cd ..
root@Eternal:/home/sigai# rm new_dir/
rm: cannot remove 'new_dir/': Is a directory
root@Eternal:/home/sigai# rm -rf new_dir/
root@Eternal:/home/sigai# ls
root@Eternal:/home/sigai# 
```

### 2.3 mv：移动文件/目录

- 移动文件：mv source_file destination_file

```bash
root@Eternal:/home/sigai# mv /home/sigai/new_dir/new_file /home/sigai/
root@Eternal:/home/sigai# ls
new_dir  new_file
```

- 移动目录：mv source_dir destination_dir

```bash
root@Eternal:/home/sigai# mv /home/sigai/new_file /home/sigai/new_dir/
root@Eternal:/home/sigai# mv /home/sigai/new_dir/ /home/
root@Eternal:/home/sigai# cd ..
root@Eternal:/home# ls
baselines  new_dir  sigai
```

- 复制目录：cp -r source_dir destination_dir

```bash
root@Eternal:/home# cd new_dir/
root@Eternal:/home/new_dir# ls
new_file
root@Eternal:/home/new_dir# cd ..
root@Eternal:/home# cp new_dir/ sigai/
cp: omitting directory 'new_dir/'
root@Eternal:/home# cp -r new_dir/ sigai/
root@Eternal:/home# cd sigai
root@Eternal:/home/sigai# ls
new_dir
```

### 2.4 cd：切换目录

- 切换至指定文件夹：cd dir_path

```bash
root@Eternal:/home/sigai# cd /home/
root@Eternal:/home# 
```

- 切换至 `home` 文件夹：cd or cd ~

```bash
root@Eternal:/home# cd 
root@Eternal:~# 
```

- 切换至上个工作目录

```bash
root@Eternal:/home/sigai# cd 
root@Eternal:~# cd -
/home/sigai
```

- 切换至上级目录

```bash
root@Eternal:~# cd ..
root@Eternal:/# 
```

- 显示当前工作路径

```bash
root@Eternal:/home/sigai# pwd
/home/sigai
```

### 2.5 ls：列出目录项

- 显示当前目录下的文件：ls 

```bash
root@Eternal:/home/sigai# cd ..
root@Eternal:/home# ls
baselines  new_dir  sigai
```

- 安装时间排序，以列表形式显示当前目录项：ls -lrt

```bash
root@Eternal:/home# ls -lrt
total 12
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 2 root  root  4096 Nov  2 03:15 new_dir
drwxr-xr-x 3 sigai sigai 4096 Nov  2 03:18 siga
```

在`.bashrc` 将常用命令设置别名，方便实用，比如使用 `lsl` 代替 `ls -lrt` ，在 `.bashrc` 中添加：

```bash
alias lsl='ls -lrt'
alias lm='ls -al|more'
```

设置完成后，看直接使用别名：

```bash
root@Eternal:/home# ls -lrt
total 12
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 2 root  root  4096 Nov  2 03:15 new_dir
drwxr-xr-x 3 sigai sigai 4096 Nov  2 03:18 sigai
root@Eternal:/home# lsl
total 12
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 2 root  root  4096 Nov  2 03:15 new_dir
drwxr-xr-x 3 sigai sigai 4096 Nov  2 03:18 sigai
root@Eternal:/home# ls -al|more
total 20
drwxr-xr-x  5 root  root  4096 Nov  2 03:16 .
drwxr-xr-x 26 root  root  4096 Nov  2 03:45 ..
drwxr-xr-x  6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x  2 root  root  4096 Nov  2 03:15 new_dir
drwxr-xr-x  3 sigai sigai 4096 Nov  2 03:18 sigai
root@Eternal:/home# lm
total 20
drwxr-xr-x  5 root  root  4096 Nov  2 03:16 .
drwxr-xr-x 26 root  root  4096 Nov  2 03:45 ..
drwxr-xr-x  6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x  2 root  root  4096 Nov  2 03:15 new_dir
drwxr-xr-x  3 sigai sigai 4096 Nov  2 03:18 sigai
```

### 2.6 find / locate：查找文件或目录

- 查找指定目录下的文件：find dir -name "file_name or dir_name" | xargs file

```bash
root@Eternal:/home# find ./ -name "sigai" | xargs file
./sigai: directory
root@Eternal:/home# find -name "sigai" 
./sigai
root@Eternal:/home# cd ..
root@Eternal:/# find -name "sigai" 
./run/sudo/ts/sigai
./home/sigai
root@Eternal:/# find "sigai"
find: ‘sigai’: No such file or directory
root@Eternal:/# find -name "sigai"
./run/sudo/ts/sigai
./home/sigai
root@Eternal:/#cd home
root@Eternal:/home# find ./ -name 'new_dir'
./sigai/new_dir
./new_dir
```

- 递归删除当前目录及子目录的文件：find ./ -name "file_name" -exec rm {} \;

```bash
root@Eternal:/home# cp -r /home/siagi/new_dir /
root@Eternal:/home# find ./ -name "new_file"
./sigai/new_dir/new_file
./new_dir/new_file
root@Eternal:/home# find ./ -name "new_file" -exec rm {} \;
root@Eternal:/home# find ./ -name "new_file"
root@Eternal:/home#
```

```bash
root@Eternal:/home# find ./ -name 'new_dir'
./sigai/new_dir
./new_dir
root@Eternal:/home# find ./ -name "new_dir" -exec rm -r {} \;
root@Eternal:/home# find ./ -name "new_dir"
root@Eternal:/home# 
```

- 另一种查找方式，查找方式根据索引查找，相对较快，但需要更新索引库：locate

```bash
root@Eternal:/home# cp -r /new_dir/ /home/
root@Eternal:/home# cp -r /home/new_dir/ /home/sigai/
root@Eternal:/home# find ./ -name  "new_dir"
./sigai/new_dir
./new_dir
root@Eternal:/home# locate "new_dir"
root@Eternal:/home# ls
baselines  new_dir  sigai
root@Eternal:/home# clear

root@Eternal:/home# updatedb
root@Eternal:/home# locate new_dir
/new_dir
/home/new_dir
/home/new_dir/new_file
/home/sigai/new_dir
/home/sigai/new_dir/new_file
/new_dir/new_file
root@Eternal:/home# 
```

### 2.7 cat：查看文件

- 带行号查看文件：cat -n file_name

```bash
root@Eternal:/home# cd new_dir/
root@Eternal:/home/new_dir# cat -n new_file 
     1	This is a new file.
```

- 按页查看文件：ls -al | more file_name

```bash
root@Eternal:/home/new_dir# ls -al | more new_file 
total 12
drwxr-xr-x 2 root root 4096 Nov  2 04:16 .
drwxr-xr-x 5 root root 4096 Nov  2 04:16 ..
-rw-r--r-- 1 root root   20 Nov  2 04:16 new_file
--More--(Next file: new_file)
::::::::::::::
new_file
::::::::::::::
This is a new file.
root@Eternal:/home/new_dir# 
```

- 显示前10行：head -10 file_name

```bash
root@Eternal:/home/new_dir# head -10 new_file 
This is a new file.
```

- 查看文件倒数第几行：tail -n file_name

```bash
root@Eternal:/home/new_dir# tail -5 new_file 
This is a new file.
```

- 比较文件：diff file_1 file_2

```bash
root@Eternal:/home/new_dir# diff new_file old_file 
1c1
< This is a new file.
---
> This is a old file.
```

### 2.8 egrep：查找文件

- 查找文件内容：egrep 'content' file_name

```bash
root@Eternal:/home# egrep 'old' new_dir/old_file 
This is a old file.
```

- 查找文件内容，并输出到指定文件：egrep 'content' file_name > find_content_file

```bash
root@Eternal:/home# egrep 'old' new_dir/old_file > find_file_content
root@Eternal:/home# cat find_file_content 
This is a old file.
```

### 2.9 chown/chmod：更改文件/目录的用户权限与使用权限

- 更改目录用户权限

```bash
root@Eternal:/home# ls -lrt
total 16
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 3 sigai sigai 4096 Nov  2 04:16 sigai
drwxr-xr-x 2 root  root  4096 Nov  2 04:29 new_dir
-rw-r--r-- 1 root  root    20 Nov  2 04:39 find_file_content
root@Eternal:/home# chown -R sigai new_dir/
root@Eternal:/home# ls -lrt
total 16
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 3 sigai sigai 4096 Nov  2 04:16 sigai
drwxr-xr-x 2 sigai root  4096 Nov  2 04:29 new_dir
-rw-r--r-- 1 root  root    20 Nov  2 04:39 find_file_content
root@Eternal:/home# chown -R root new_dir/
root@Eternal:/home# ls -lrt
total 16
drwxr-xr-x 6 root  root  4096 Mar 27  2019 baselines
drwxr-xr-x 3 sigai sigai 4096 Nov  2 04:16 sigai
drwxr-xr-x 2 root  root  4096 Nov  2 04:29 new_dir
-rw-r--r-- 1 root  root    20 Nov  2 04:39 find_file_content
root@Eternal:/home# su sigai
sigai@Eternal:/home$ chown -R root new_dir/
chown: changing ownership of 'new_dir/old_file': Operation not permitted
chown: changing ownership of 'new_dir/new_file': Operation not permitted
chown: changing ownership of 'new_dir/': Operation not permitted
```

- 更改文件权限

```bash
root@Eternal:/home# chmod a+x new_dir/new_file
root@Eternal:/home# cd new_dir/
root@Eternal:/home/new_dir# ll
total 16
drwxr-xr-x 2 sigai root 4096 Nov  2 04:29 ./
drwxr-xr-x 5 root  root 4096 Nov  2 04:39 ../
-rwxr-xr-x 1 sigai root   20 Nov  2 04:16 new_file*
-rw-r--r-- 1 sigai root   20 Nov  2 04:29 old_file
```

### 2.10 ln：给文件增加别名

- 硬链接：ln file link_file

&emsp;&emsp;硬链接在源文件删除后，链接仍能使用，

```bash
root@Eternal:/home# ln new_dir/new_file link_new
root@Eternal:/home# ls
baselines  find_file_content  new_dir  sigai  link_new
```

- 软链接：ln -s file soft_link_file

```bash
root@Eternal:/home# ln -s new_dir/new_file soft_link_new
root@Eternal:/home# ll
total 24
drwxr-xr-x  5 root  root  4096 Nov  2 05:11 ./
drwxr-xr-x 27 root  root  4096 Nov  2 04:10 ../
drwxr-xr-x  6 root  root  4096 Mar 27  2019 baselines/
-rw-r--r--  1 root  root    20 Nov  2 04:39 find_file_content
drwxr-xr-x  2 root  root  4096 Nov  2 05:10 new_dir/
drwxr-xr-x  3 sigai sigai 4096 Nov  2 04:16 sigai/
lrwxrwxrwx  1 root  root    16 Nov  2 05:11 soft_link_new -> new_dir/new_file

root@Eternal:/home# rm new_dir/new_file 
root@Eternal:/home# ll
total 24
drwxr-xr-x  5 root  root  4096 Nov  2 05:11 ./
drwxr-xr-x 27 root  root  4096 Nov  2 04:10 ../
drwxr-xr-x  6 root  root  4096 Mar 27  2019 baselines/
-rw-r--r--  1 root  root    20 Nov  2 04:39 find_file_content
drwxr-xr-x  2 root  root  4096 Nov  2 05:11 new_dir/
drwxr-xr-x  3 sigai sigai 4096 Nov  2 04:16 sigai/
lrwxrwxrwx  1 root  root    16 Nov  2 05:11 soft_link_new -> new_dir/new_file
root@Eternal:/home# cat soft_link_new 
cat: soft_link_new: No such file or directory

```

硬链接只能用于文件，不能用于目录；软链接可以为目录建链接。



### 2.11 > / >>：管道和重定向

- 批处理命令执行：|

- 串联使用分号：;

- 前面成功，则执行后面一条，否则，不执行:&&
- 前面失败，则后一条执行: ||

```bash
root@Eternal:/home# ls /proc && echo suss! || echo failed
1     14639  29    378   56    824        diskstats    mtrr
10    14642  291   380   57    828        dma          net
1089  15     3     384   58    843        driver       pagetypeinfo
1091  16     30    386   5879  850        execdomains  partitions
1092  17     3117  390   59    857        fb           sched_debug
1093  170    3118  391   60    861        filesystems  schedstat
1094  18     3137  392   61    868        fs           scsi
1095  1820   3138  397   62    887        interrupts   self
11    1867   3165  4181  63    895        iomem        slabinfo
1132  19     3166  4182  64    897        ioports      softirqs
1134  2      318   4251  65    8973       irq          stat
1135  20     3184  4254  66    9          kallsyms     swaps
12    21     3185  443   67    907        kcore        sys
1207  22     3199  45    68    95         keys         sysrq-trigger
1297  22044  320   46    69    96         key-users    sysvipc
13    23     3200  47    7     989        kmsg         thread-self
137   2354   321   48    70    acpi       kpagecgroup  timer_list
138   258    3231  49    71    asound     kpagecount   timer_stats
139   26721  3232  5     72    buddyinfo  kpageflags   tty
14    27     3266  50    73    bus        loadavg      uptime
140   27065  3267  51    74    cgroups    locks        version
142   27357  3327  52    7439  cmdline    mdstat       version_signature
143   2776   3328  5204  75    consoles   meminfo      vmallocinfo
144   2777   3574  53    76    cpuinfo    misc         vmstat
145   28     3578  54    8     crypto     modules      zoneinfo
146   2836   367   55    81    devices    mounts
suss!
```

等价于 `if...;then...;else...;fi`

```bash
root@Eternal:/home# if ls /proc; then echo suss; else echo fail; fi
1      14642  3     380   58    850          fb            schedstat
10     15     30    384   5879  857          filesystems   scsi
1089   16     3117  386   59    861          fs            self
1091   17     3118  390   60    868          interrupts    slabinfo
1092   170    3137  391   61    887          iomem         softirqs
1093   18     3138  392   62    895          ioports       stat
1094   1820   3165  397   63    897          irq           swaps
1095   1867   3166  4181  64    8973         kallsyms      sys
11     19     318   4182  65    9            kcore         sysrq-trigger
1132   2      3184  4251  66    907          keys          sysvipc
1134   20     3185  4254  67    95           key-users     thread-self
1135   21     3199  443   68    96           kmsg          timer_list
12     22     320   45    69    989          kpagecgroup   timer_stats
1207   22044  3200  46    7     acpi         kpagecount    tty
1297   23     321   47    70    asound       kpageflags    uptime
13     2354   3231  48    71    buddyinfo    loadavg       version
137    258    3232  49    72    bus          locks         version_signature
138    26721  3266  5     73    cgroups      mdstat        vmallocinfo
139    27     3267  50    74    cmdline      meminfo       vmstat
14     27065  3327  51    7439  consoles     misc          zoneinfo
140    27357  3328  52    75    cpuinfo      modules
142    2776   3574  5204  76    crypto       mounts
143    2777   3579  53    8     devices      mtrr
144    28     3584  54    81    diskstats    net
145    2836   3588  55    824   dma          pagetypeinfo
146    29     367   56    828   driver       partitions
14639  291    378   57    843   execdomains  sched_debug
suss
```

- 将标准输入输出重定向至文件：ls proc/*.c &> list

```bash
root@Eternal:/home# ls proc/*.c &> list
root@Eternal:/home# ls
baselines  find_file_content  list  new_dir  sigai  soft_link_new
root@Eternal:/home# cat list
ls: cannot access 'proc/*.c': No such file or directory
```

清空文件：: > file_name

```bash
root@Eternal:/home# :> list
root@Eternal:/home# cat list
root@Eternal:/home# 
```

重定向：>>

```bash
root@Eternal:/home# cat new_dir/old_file -n >> list 
root@Eternal:/home# cat list
     1	This is a old file.
```

### 2.12 Bash 快捷键

- Ctl-U 删除光标到行首的所有字符,在某些设置下,删除全行 
- Ctl-W 删除当前光标到前边的最近一个空格之间的字符 
- Ctl-H backspace,删除光标前边的字符 
- Ctl-R 匹配最相近的一个文件，然后输出



## 参考

1. [文件及目录管理](https://linuxtools-rst.readthedocs.io/zh_CN/latest/base/02_file_manage.html)
2. [硬链接，软链接，拷贝的区别](https://blog.csdn.net/geerniya/article/details/79093301)

