#!/bin/bash
# Timetrack
#
# This is a script written for the course
# Linux as development environment. It is
# the solution to task 1f in Tema 10.
#
# The script takes a command as input, and
# can handle the commands start, stop and
# status
# start  - Starts a counter
# stop   - Stops the counter and outputs the
#          time passed since started
# status - If the timer is started it outputs
#          the time passed since started.


# Get the command
command=$1

# Support function to print the time since
# timer was started
function outputTime {
  old_sec=`cat timetrack.txt`
  new_sec=`date +%s`
  sec=$(($new_sec-$old_sec))
  echo -n $sec
}

# Act on the command passed to the ecript
case "$command" in
  "start")
    # Start timer if not already started
    if [[ -e timetrack.txt ]]; then
      echo "Tiden har redan startats"
    else
      echo "Tiden startad"
      echo `date +%s` > timetrack.txt
    fi
    ;;
  "stop")
    # Stop the timer and output time if it has been started
    if [[ -e timetrack.txt ]]; then
      echo "Tiden stoppad efter `outputTime` sekunder"
      rm -f timetrack.txt
    else
      echo "Tiden har inte startats"
    fi
    ;;
  "status")
    # If timer started output time since started, otherwise
	# output that the timer has not yet been started
    if [[ -e timetrack.txt ]]; then
      echo "Det har gått `outputTime` sekunder sedan start"
    else
      echo "Timetrack ej aktiv"
    fi   
    ;;
  *)
    # Unknown command, output help text
    echo "Okänt kommando!"
    echo "start  - starta räknaren"
    echo "stop   - stoppa räknaren och visa tid"
    echo "status - visa tid sedan start"
	;;
esac
