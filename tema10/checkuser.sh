#!/bin/bash

# Get the user name passed to the script
user=$1

# If no user is passed to the script, then prompt the user for a
# user name. Timeout after 60 seconds
if [[ -z $user ]]; then
  read -t 15 -p "Enter the user name to check is online: " user
  if [[ $? -ne 0 ]]; then echo "Timed out after 15s!"; exit 127; fi
fi

# Checked for the users logged in at the moment and pipe it
# to grep to check for the user name passed to the script
# and then exit with the same exit code as grep, thus 0 if successful
# and non zero if user is not found
users | grep -q $user
exit $?
