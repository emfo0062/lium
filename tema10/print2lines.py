#!/usr/bin/env python
import os
import sys

if len(sys.argv) == 1:
  print "You need to provide a path to look in"
  print sys.argv[0] + " <path>"

dirPath = sys.argv[1]
print "print2lines will now print first 2 lines of each file in the directory " + dirPath
print "--------------------------------------"

try:
  for file in os.listdir(dirPath):
      if file.endswith(".txt"):
          fh = open(file)
          line1 = fh.readline().rstrip().decode('UTF-8')
          line2 = fh.readline().rstrip().decode('UTF-8')
          fh.close()
          print file + ":"
          if line1 != "": print line1 + " " + line2
          print "--------------------------------------"
except:
    print "Failed to parse " + dirPath
    print "Error message:\n",sys.exc_info()

