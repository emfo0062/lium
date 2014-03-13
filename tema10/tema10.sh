#!/bin/bash

function my_write {
  echo "$@"
}

function my_time {
  echo "Date: " `date`
  echo "Seconds since 1970-01-01:" `date +%s`
}

function write_sec {
  echo Write seconds to file
  echo `date +%s` > datefile
}

function comp_sec {
  old_sec=`head -n1 datefile`
  new_sec=`date +%s`
  sec=$(($new_sec-$old_sec))
  echo "Seconds since file was written: $sec"
}

function count_use {
  cmd=$1
  if [[ $cmd == "in" ]]; then
    if [[ -e count.log ]]; then
      cnt=$((`cat count.log` + 1))
    else
      cnt=1
    fi
    echo $((cnt)) > count.log
  elif [[ $cmd == "ut" ]]; then
    if [[ -e count.log ]]; then
      cnt=`cat count.log`
      [[ $cnt -gt 0 ]] && cnt=$(($cnt-1))
    else
      cnt=0
    fi
    echo $((cnt)) > count.log
  else
    echo "Don't understand! Use in or ut"
    exit 127
  fi
  [[ $cnt -gt 0 ]] && echo "Inloggad"
  [[ $cnt -eq 0 ]] && echo "Utloggad"
}
