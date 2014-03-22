#!/bin/bash

source tema10.sh

echo "**** Testing a ****"
hw="Hello world2"
my_write "Hello world"
my_write $hw

echo "**** Testing b ****"
my_time

echo "****  Testing c ****"
write_sec

echo "**** Testing d ****"
sleep 1
comp_sec

echo "**** Testing e ****"
rm -f count.log
count_use in
if [[ `cat count.log` -eq 1 ]];then echo "[OK]";else echo "[FAIL]";fi
count_use in
if [[ `cat count.log` -eq 2 ]];then echo "[OK]";else echo "[FAIL]";fi
count_use ut
if [[ `cat count.log` -eq 1 ]];then echo "[OK]";else echo "[FAIL]";fi
count_use ut
if [[ `cat count.log` -eq 0 ]];then echo "[OK]";else echo "[FAIL]";fi
count_use ut
if [[ `cat count.log` -eq 0 ]];then echo "[OK]";else echo "[FAIL]";fi
count_use in
if [[ `cat count.log` -eq 1 ]];then echo "[OK]";else echo "[FAIL]";fi

echo "**** Testing timetrack (f) ****"
./timetrack.sh status
./timetrack.sh start
sleep 1
./timetrack.sh status
sleep 1
./timetrack.sh stop
./timetrack.sh status
./timetrack.sh start
sleep 1
./timetrack.sh stop

echo "**** Testing checkuser (g) ****"
echo "Testing with `whoami`"
./checkuser.sh `whoami`
if [[ $? -eq 0 ]];then echo "[OK]";else echo "[FAIL]";fi
echo "Testing with xxx`whoami`"
./checkuser.sh xxx`whoami`
if [[ $? -eq 0 ]];then echo "[OK]";else echo "[OK]";fi

echo "**** Testing print2lines.py (h) *****"
./print2lines.py