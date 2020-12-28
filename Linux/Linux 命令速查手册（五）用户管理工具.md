# Linux 命令速查手册（五）用户管理工具

[TOC]

## 5 用户管理工具

### 5.1 useradd：添加用户

- useradd -m username：创建 `username` 并在 `/home/` 目录下创建相应文件夹。

```bash
root@Eternal:/home# useradd -m username
root@Eternal:/home# ls
baselines  find_file_content  list  new_dir  sigai  soft_link_new  username
root@Eternal:/home# 
```

### 5.2 passwd：为用户设置密码

- passwd username：为 `username` 设置密码

```bash
root@Eternal:/home# passwd username
Enter new UNIX password: 
Retype new UNIX password: 
passwd: password updated successfully
```

### 5.3 userdel：删除用户

- userdel -r username：删除用户及用户目录

```bash
root@Eternal:/home# userdel -r username
userdel: username mail spool (/var/mail/username) not found
root@Eternal:/home# ls
baselines  find_file_content  list  new_dir  sigai  soft_link_new
root@Eternal:/home# 
```

### 5.4 su：切换用户

- su username：切换至 `username` 用户

```bash
root@Eternal:/home# su sigai
sigai@Eternal:/home$ su root
Password: 
root@Eternal:/home# 
```

### 5.5 group：用户组

- group：查看当前用户所在的用户组

```bash
root@Eternal:/home# groups
root
root@Eternal:/home# 
```

- usermod 
  - -G root sigai：将用户 `sigai` 添加至 `root` 组
  - -g root sigai：将用户 `sigai` 添加至 `root` 组，并且从原来的组中删去

```bash
root@Eternal:/home# usermod -G root sigai
root@Eternal:/home# su sigai
sigai@Eternal:/home$ groups
sigai root
root@Eternal:/home# usermod -g root sigai
root@Eternal:/home# su sigai
sigai@Eternal:/home$ groups
root
```

- more 
  - /etc/passwd：查看所有的用户及权限
  - /etc/groups：查看系统所有组

```bash
root@Eternal:/home# more /etc/passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
...
root@Eternal:/home# more /etc/group
root:x:0:sigai
daemon:x:1:
bin:x:2:
sys:x:3:
adm:x:4:syslog
tty:x:5:
disk:x:6:
lp:x:7:
...
```

### 5.6 chmod：用户权限

```bash
root@Eternal:/home# ls -l
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwxr-xr-x 2 root  root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
root@Eternal:/home# 
```

&emsp;&emsp;文件属性字段总共有10个字母组成，第一个字母表示文件类型，如果这个字母是一个减号”-”,则说明该文件是一个普通文件。字母”d”表示该文件是一个目录，字母”d”,是dirtectory(目录)的缩写。 后面的9个字母为该文件的权限标识，3个为一组，分别表示文件所属用户、用户所在组、其它用户的读写和执行权限；



- chmod usermark(+/-)PermissionMark
  - userMark取值：
    - u：用户
    - g：组
    - o：其它用户
    - a：所有用户
  - PermissionsMark取值：
    - r:读
    - w：写
    - x：执行

```bash
root@Eternal:/home# chmod a+w new_dir/
root@Eternal:/home# ls -l
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwxrwxrwx 2 root  root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
```

- chmod 700 file：将文件权限设置为 `700`
  - 数字形式：使用三位八进制数字的形式来表示权限，第一位指定属主的权限，第二位指定组权限，第三位指定其他用户的权限，每位通过4(读)、2(写)、1(执行)三种数值的和来确定权限。如6(4+2)代表有读写权，7(4+2+1)有读、写和执行的权限。

```bash
root@Eternal:/home# chmod 700 new_dir/
root@Eternal:/home# ls -l
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwx------ 2 root  root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
```



### 5.8 chown：修改文件或目录持有者

- chown username directory：将目录使用者权限更改为 `username`

```bash
root@Eternal:/home# ls -l 
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwx------ 2 root  root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
root@Eternal:/home# chown sigai new_dir/
root@Eternal:/home# ls -l
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwx------ 2 sigai root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
root@Eternal:/home# cd new_dir/
root@Eternal:/home/new_dir# ls -l
total 4
-rw-r--r-- 1 root root 20 Nov  2 04:29 old_file
```

- chown -R username directory：将目录及目录下的文件使用者权限递归的更改为 `username`

```bash
oot@Eternal:/home/new_dir# cd ..
root@Eternal:/home# chown -R sigai new_dir/
root@Eternal:/home# ls -l
total 20
drwxr-xr-x 6 root  root 4096 Mar 27  2019 baselines
-rw-r--r-- 1 root  root   20 Nov  2 04:39 find_file_content
-rw-r--r-- 1 root  root   27 Nov  2 05:25 list
drwx------ 2 sigai root 4096 Nov  2 05:11 new_dir
drwxr-xr-x 3 sigai root 4096 Nov  5 10:03 sigai
lrwxrwxrwx 1 root  root   16 Nov  2 05:11 soft_link_new -> new_dir/new_file
root@Eternal:/home# cd new_dir/
root@Eternal:/home/new_dir# ls -l
total 4
-rw-r--r-- 1 sigai root 20 Nov  2 04:29 old_file
```

### 5.9 bashrc / profile：环境变量

#### bashrc / profile

`bashrc` 与 `profile` 都用于保存用户的环境信息，`bashrc` 用于交互式 `non-loginshell` ，而 `profile` 用于交互式`login shell`。

`/etc/profile` ，`/etc/bashrc`  是系统全局环境变量设定

`~/.profile`，`~/.bashrc` 用户目录下的私有环境变量设定



#### 当系统获得一个shell进程时，读取环境设置脚本分为三步：

1. 读入全局环境变量 `/etc/profile` ，根据内容读取 `/etc/profile.d` 和 `/etc/inputrc`
2. 读取当前登陆用户的 `HOME` 目录下的 `~/.bash_profile` ，然后是 `~/.bash_login` ，最后读取 `~/.profile`
3.  读取 `~/bashrc`



#### ~/.bashrc v.s. ~/.profile

1. 两个文件都可以自定义设置
2. `~/.profile` 可以设置当前用户专有的路径，环境变量等。在登录时只执行一次。
3. `~/.bashrc` 也为当前用户专有的设定文档，可以设置路径，别名。每次登陆 `shell script` 时都会执行。

