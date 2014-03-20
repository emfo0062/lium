#!/usr/bin/env python
import os

dirPath = "."
print "print2lines will now print first 2 lines of each file in the directory " + dirPath
print "--------------------------------------"

for file in os.listdir(dirPath):
    if file.endswith(".txt"):
      fh = open(file)
      line1 = fh.readline().rstrip()
      line2 = fh.readline().rstrip()
      fh.close()
      print file + ":"
      print "1: " + line1
      print "2: " + line2
      print "--------------------------------------"

print "That's all for now folks..."
