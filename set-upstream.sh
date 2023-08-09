#!/bin/sh

#git clone git@github.com:bm4cs/dwm
#git clone git@github.com:IsakRehle/dwm
git remote add upstream git://git.suckless.org/dwm
git remote add github git@github.com:IsakRehle/dwm
git fetch upstream
git fetch github
git branch --set-upstream-to=github/isak
git branch master
git checkout master
git branch --set-upstream-to=upstream/master
git pull
git checkout isak
git rebase --rebase-merges master

##git clone git@github.com:bm4cs/dwm
#git remote add upstream git://git.suckless.org/dwm
#git remote add github git@github.com:IsakRehle/dwm.git
#git fetch upstream
#git fetch github
#git branch --set-upstream-to=github/isak
#git branch master
#git checkout master
#git branch --set-upstream-to=upstream/master
#git pull
#git checkout isak
#git rebase --rebase-merges master

