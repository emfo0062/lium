Tema 10
-------
This folder contains my solution to Tema 10. It contains three scripts.

checkuser.sh
------------
This is a shell script will check if a user is logged in to the system.

timetrack.sh
------------
This is a shell script that will take three arguments start, status and stop. Start will register the time of the command. Status will report how long ago it was since start was run. Stop will output the timesince start was run and clear the time, so that start will have to be run again before a new status can be run.

print2lines.py
--------------
This is a python script that will print the two first rows of each text file (*.txt) in the folder that is past as an argument to the script. Unvalid paths will be caught by a try and except. The paths can be both absolute and relative.
