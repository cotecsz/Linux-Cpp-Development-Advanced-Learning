# [Git札记 2] Github 常用操作及其命令

Git系列笔记记录日常Git命令使用。

[TOC]

## 开始管理仓库

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



## 常用操作

### 撤销 commit  (NOT PUSH)

```bash
git commit --amend
```





### 更改目录/文件名

```bash
git mv old_directory[old_file] new_directory[old_file] 
```



### 从远程仓库拉取更新本地仓库

#### Fetch directly to local and merge remote

1. 在GitHub修改了文件，比如修改文件名，或者修改了文件
2. 将远程仓库拉取至本地仓库

```bash
git remote -v # 查看远程仓库
git fetch origin master# 拉取仓库至本地
```

3. 比较本地仓库与远程仓库区别

```bash
git log -p master.. origin/master
```

4. 合并本地仓库

```bash
git merge origin/master
```

#### Fetch indirectly to temp local and merge remote or delete temp

1. 查看远程仓库

```bash
git remote -v 
```

2. 拉取仓库，暂存至本地暂存区

```bash
git fetch origin master:temp
```

3. 比较本地仓库和远程仓库

```bash
git diff temp
```

4. 合并/删除 `temp` 分支至 `master` 分支

```bash
git merge temp # 合并
git branch -D temp # 删除
```



## 其他

1. 在 `Terminal` 查看使用Git 查看 `git status` ，中文使用八进制显示，如何解决？

```bash
git config --global core.quotepath false
```

2. Mac 修改文件后，`git status ` 无显示，如何设置全局忽略 `DS_Store`？

   - 添加编辑 `home` 目录下的 `.gitignore_global` 文件

   ```bash
   vi ~/.gitignore_global
   ```

   - 添加下面两行

   ```
   .DS_Store
   */.DS_Store
   ```

   - 查看 `home` 目录

   ```bash
   pwd
   ```

   - 修改 `home` 目录下 `gitconfig` 文件， 添加全局忽略规则

   ```bash
   vi ~/.gitconfig
   ```

   ```
   [core]
   	 excludesfile = /Users/zxxair/.gitignore_global
   ```

   - 若修改中仍有 `.DS_Store` 文件，可能是已提交至Github，需要删除。
   
   ```bash
   git rm --cached .DS_Store
   find . -name .DS_Store -print0 | xargs -0 git rm --ignore-unmatch
   ```
   
   

## Reference

1. [Git重命名文件和文件夹](https://blog.csdn.net/shenwanjiang111/article/details/78776191)
2. [Git修改上次提交的Commit](https://segmentfault.com/q/1010000000761908)
3. [更新远程仓库至本地](https://blog.csdn.net/u012150179/article/details/17172211)
4. [Mac git忽略.DS_Store](https://www.jianshu.com/p/e3d8eb2a4295)