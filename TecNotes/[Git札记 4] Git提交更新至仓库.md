# [Git札记 4] Git提交更新到仓库

本篇笔记用于记录Git 跟踪修改的过程，如何通过git 来提交更新。

<!--more-->

[TOC]

## Git 生命周期

在本地的工作目录下，文件有且仅有两种状态：

1. Untracted（未跟踪）
2. tracted（已跟踪）
   - Unmodified（未修改）
   - Modified（已修改）
   - Staged（已暂存）

关系如下图所示：

<div align='center'>
  <img src='assets/image-20190819080159879.png' width='800'
</div>

下面将一一介绍上面的4中状态。

### Untracked

这里使用一个已有的仓库进行演示，仓库文件目录如下：

```bash
- NewRepositoryDemo
	-	Hello_GitHub.py
	- README.md
```

首先，在仓库中创建 `README` 文件，查看仓库状态

```bash
$ git init
$ echo 'This is a README file.' > README
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	README

nothing added to commit but untracked files present (use "git add" to track)
```

> 在本地目录下，新建的文件未 `Untracked` 文件。

### Staged

对于 `Untracked` 文件，需要让 `Git` 进行跟踪

```bash
$ git add README
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   README
```

> 对于 `Untracked` 文件，`git add <file>` 使得git 开始跟踪文件，此时文件状态为 `staged` 。

### Modified and Unmodified

修改 `Hello_GitHub.py` ，文件状态为 `Modified`：

```bash
$ echo 'print('Modified')' > Hello_GitHub.py
$ git add Hello_GitHub.py
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   Hello_GitHub.py
	new file:   README
```

将文件  `git add ` 后，再次修改，查看文件状态：

```bash
$ vi Hello_GitHub.py
add `print(Modified again)`
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	modified:   Hello_GitHub.py
	new file:   README

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   Hello_GitHub.py
```

查看文件状态后会看到两个 `modified: Hello_GitHub.py` ，第一个是添加至暂存区的文件，第二个至添加至暂存区后，又对文件进行了修改，生成了新的记录，需要将记录添加至暂存区。



## 比较更新

查看工作目录中当前文件和暂存区域之间的差异，即修改之后还有暂存的变化内容：

```bash
git diff
```

查看已暂存的内容，即下次提交的内容：

```bash
git diff --staged
```



## 提交更新

1. 设置提交更新时启动的编译器

   ```bash
   git config --global core.editor vim	
   ```

2. 提交更新，自动启动编辑器，添加修改信息

   ```bash
   git commit
   ```

3. 简短的提交信息

   ```bash
   git commmit -m 'message'
   ```

4. 跳过暂存区直接提交

   ```bash
   git commit -a -m 'message'
   ```



## 移除文件

在提交更新时，可能将一些额外的文件上传，需要撤销上传或者不跟踪该文件，如何在git 中移除该文件？

1. 新添加的文件  `del.py` ，将文件添加至暂存区

   ```bash
   $ touch del.py
   $ vi del.py
   ... # add context
   $ git add del.py
   $ git status
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Changes to be committed:
     (use "git reset HEAD <file>..." to unstage)
   
   	modified:   Hello_GitHub.py
   	new file:   README
   	new file:   del.py
   ```

2. 删除 / 恢复 暂存区的文件

   ```bash
   $ git rm del.py
   error: the following file has changes staged in the index:
       del.py
   (use --cached to keep the file, or -f to force removal)
   ```

   上述提示，使用 `--cached ` 保留文件，仅删除暂存区的 `del.py` ，此时，文件状态为未跟踪状态

   ```bash
   $ git rm --cached del.py
   rm 'del.py'
   $ git status 
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Changes to be committed:
     (use "git reset HEAD <file>..." to unstage)
   
   	modified:   Hello_GitHub.py
   	new file:   README
   
   Untracked files:
     (use "git add <file>..." to include in what will be committed)
   
   	del.py
   ```

   使用 `-f` 强制删除，该文件则在**暂存区**和**本地**同时删除

   ```bash
   $ git rm -f del.py
   rm 'del.py'
   $ ls -l
   total 24
   -rw-r--r--  1 lyj  staff  38  8 19 08:42 Hello_GitHub.py
   -rw-r--r--  1 lyj  staff  23  8 19 08:18 README
   -rw-r--r--  1 lyj  staff  76  8  9 13:22 README.md
   ```

3. 若文件已上传至仓库，想要删除仓库中的 `del.py` ，但保留本地的文件

   ```bash
   $ git rm --cached del.py
   rm 'del.py'
   $ git status 
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Changes to be committed:
     (use "git reset HEAD <file>..." to unstage)
   
   	deleted:    del.py
   
   Untracked files:
     (use "git add <file>..." to include in what will be committed)
   
   	del.py
   $ git commit -m 'delete del.py'
   [master fc44c77] delete del.py
    1 file changed, 3 deletions(-)
    delete mode 100644 del.py
   $ git push
   $ git status
   On branch master
   Your branch is up to date with 'origin/master'.
   
   Untracked files:
     (use "git add <file>..." to include in what will be committed)
   
   	del.py
   
   nothing added to commit but untracked files present (use "git add" to track)
   
   ```

   此时文件状态为 `Untracked`，添加至 `.gitignore` , 使得 git 忽略该文件。



## 移动文件

在修改文件时，可能将文件 / 文件夹名称写错，如何修改文件名？下面修改 `Hello_GitHub.py` 文件名。

```bash
$ git mv Hello_GitHub.py Hello_Github.py
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	renamed:    Hello_GitHub.py -> Hello_Github.py

```



## 查看提交历史

1. 使用命令查看历史修改，[命令](https://git-scm.com/book/zh/v1/Git-%E5%9F%BA%E7%A1%80-%E6%9F%A5%E7%9C%8B%E6%8F%90%E4%BA%A4%E5%8E%86%E5%8F%B2)
2. 图形化界面



## 撤销操作

### 在 `commit` 后，发现有文件需要提交

```bash
$ git commit -m 'commit firstly'
$ git add forgotten_file
$ git commit --amend
```

### 在 `add` 后，取消暂存文件

```bash
$ git add .
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	renamed:    Hello_GitHub.py -> Hello_Github.py
	new file:   del.py
```

这里，撤销对 `del.py` 的修改，看提示，使用 `git reset HEAD <file>` 去撤销暂存：

```bash
$ git reset HEAD del.py
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	renamed:    Hello_GitHub.py -> Hello_Github.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	del.py
```

`del.py` 文件已经恢复至 `Untracked ` 状态。

### 未添加至暂存区的文件，修改后，撤销修改

```bash
$ vi Hello_Github.py
# ... add context
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	renamed:    Hello_GitHub.py -> Hello_Github.py

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   Hello_Github.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	del.py
```

查看提示，使用 `git checkout -- <file>...` 来撤销修改在工作目录中

```bash
$ git checkout -- Hello_Github.py 
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	renamed:    Hello_GitHub.py -> Hello_Github.py

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	del.py

```

完成撤销本地修改。



## 开始使用远程仓库

查看远程仓库

```bash
$ git remote
origin
$ git remote -v
origin	https://github.com/cooldeepAI/NewRepositoryDemo.git (fetch)
origin	https://github.com/cooldeepAI/NewRepositoryDemo.git (push)
```



