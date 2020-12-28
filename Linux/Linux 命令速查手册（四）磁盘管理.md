# Linux 命令速查手册（四）磁盘管理

[TOC]

## 4 磁盘管理

### 4.1 df：查看磁盘大小

- df -h：查看磁盘空间利用大小
- df -sh：查看当前目录所占空间大小

```bash
root@Eternal:~# df -h
Filesystem      Size  Used Avail Use% Mounted on
udev            225M     0  225M   0% /dev
tmpfs            49M  8.1M   41M  17% /run
/dev/vda1       9.6G  4.8G  4.4G  53% /
tmpfs           245M   28K  245M   1% /dev/shm
tmpfs           5.0M     0  5.0M   0% /run/lock
tmpfs           245M     0  245M   0% /sys/fs/cgroup
tmpfs            49M     0   49M   0% /run/user/0
root@Eternal:~# du -sh
442M	.
root@Eternal:~# du -sh `ls` | sort
16K	shadowsocksR.sh
345M	Programfile
4.0K	agentpolis-javadoc
4.0K	jupyter_projects
4.0K	repo
52K	shadowsocksR.log
68M	miniconda.sh
8.0K	index.html
```



### 4.2 tar：打包/压缩

- tar -cvf file.tar /file：将 `file` 文件打包

```bash
root@Eternal:/home/sigai# tar -cvf new_dir.tar /new_dir/
tar: Removing leading `/' from member names
/new_dir/
/new_dir/new_file
root@Eternal:/home/sigai# ls
new_dir  new_dir.tar
root@Eternal:/home/sigai# 
```

- gzip file.txt：压缩文件

```bash
root@Eternal:/home/sigai/new_dir# gzip new_file table.txt paste_file 
root@Eternal:/home/sigai/new_dir# ls
new_file.gz  paste_file.gz  table.txt.gz
```



### 4.3 tar：解包/解压缩

- tar -xvf file.tar：将 `file.tar` 解包

```bash
root@Eternal:/home/sigai# tar -xvf new_dir.tar 
new_dir/
new_dir/new_file
```

- gunzip file.gz：将 `file.gz` 解压缩

```bash
root@Eternal:/home/sigai/new_dir# gunzip table.txt.gz 
root@Eternal:/home/sigai/new_dir# ls
new_file  new_file.gz  paste_file.gz  table.txt
```

