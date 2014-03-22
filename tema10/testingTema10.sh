#!/bin/bash

function main {
  while test $# -gt 0
  do
    case "$1" in
      "1f")
        test_1f
        ;;
      "1g")
         test_1g
        ;;
      "2")
        test_2
        ;;
      *)
	    test_1f
        test_1g
        test_2
        ;;
    esac
    shift
  done
}

function test_1f {
  echo "**** Testing timetrack (1f) ****"
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
}

function test_1g {
  echo "**** Testing checkuser (1g) ****"
  echo "Testing with `whoami`"
  ./checkuser.sh `whoami`
  if [[ $? -eq 0 ]];then echo "[OK]";else echo "[FAIL]";fi
  echo "Testing with xxx`whoami`"
  ./checkuser.sh xxx`whoami`
  if [[ $? -eq 0 ]];then echo "[OK]";else echo "[OK]";fi
}

function test_2 {
  echo "**** Testing print2lines.py (2) *****"
  for dir in {'.','test/with/a/faulty/path',`pwd`,"`pwd` `pwd`/txtFiles"}; do
    echo "=== Test with dir: $dir ==="
    ./print2lines.py $dir
	echo
  done
}

main $@