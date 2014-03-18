#!/bin/bash

command=$1

function outputTime {
  old_sec=`cat timetrack.txt`
  new_sec=`date +%s`
  sec=$(($new_sec-$old_sec))
  echo -n $sec
}
case "$command" in

"start")
  if [[ -e timetrack.txt ]]; then
    echo "Tiden har redan startats"
  else
    echo "Tiden startad"
    echo `date +%s` > timetrack.txt
  fi
  ;;
"stop")
  if [[ -e timetrack.txt ]]; then
    echo "Tiden stoppad efter `outputTime` sekunder"
    rm -f timetrack.txt
  else
    echo "Tiden har inte startats"
  fi
  ;;
"status")
  if [[ -e timetrack.txt ]]; then
    echo "Det har gått `outputTime` sekunder sedan start"
  else
    echo "Timetrack ej aktiv"
  fi   
  ;;
*)
  echo "Okänt kommando!"
  echo "start  - starta räknaren"
  echo "stop   - stoppa räknaren och visa tid"
  echo "status - visa tid sedan start"
esac
