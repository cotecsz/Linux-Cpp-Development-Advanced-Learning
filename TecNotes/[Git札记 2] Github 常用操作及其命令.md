# [Git] Github 常用操作及其命令

Git系列笔记记录日常Git命令使用。

[TOC]

## Start to Manage Your Projects

1. 在 `GitHub` 上新建一个项目（详细参照上一篇 `GitHub使用指南` ） 
2. 在本地创建文件夹以保存项目

```bash
cd ~/Desktop
mkdir Git_Projects
```

3. 将远程项目同步至本地

```bash
git clone https://github.com/cooldeepAI/Learning_Notes.git
```

4. 查看 `~/Desktop/Git_Projects` 目录下有 `Learning_Notes` 工程，可在工程目录下做修改
5. 提交修改至本地仓库

```bash
git status
git add new_file
git commit -m "add new_file"
```

6. 提交修改至远程仓库

```bash
git push
or git push origin master
```



## Common Commands

### Change directory name or file name

```bash
git mv old_directory[old_file] new_directory[old_file] 
```

### Revoke commit (NOT PUSH)

```bash
git commit --amend
```



## Reference

1. [Git重命名文件和文件夹](https://blog.csdn.net/shenwanjiang111/article/details/78776191)
2. [Git修改上次提交的Commit](https://segmentfault.com/q/1010000000761908)