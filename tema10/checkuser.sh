#!/bin/bash

user=$1

users | grep -q $user
exit $?
