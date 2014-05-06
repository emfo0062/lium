#!/usr/bin/env python
import os
import sys

# Verify that the user has given an argument
if len(sys.argv) == 1:
    print "You need to provide a path to look in"
    print sys.argv[0] + " <path>"

print "print2lines will print the first 2 lines of each file in the directories given"

# Evaluate all paths given as input
for dirPath in sys.argv[1:]:
    print "\nParse directory " + dirPath
    print "--------------------------------------"
    try:
        # Find all the files in dirPath
        for file in os.listdir(dirPath):
            # Check if they have the txt extension
            if file.endswith(".txt"):
                try:
                    # If it is a text file, then read and output
                    # the first two lines of the file.
                    fh = open(dirPath+"/"+file)
                    line1 = fh.readline().rstrip().decode('UTF-8')
                    line2 = fh.readline().rstrip().decode('UTF-8')
                    fh.close()
                    # Output the result
                    print file + ":"
                    print line1 + " " + line2
                    # Catch IOExceptions while reading the file
                except IOError:
                    print "Failed to read " + file
                    print "Error message:\n",sys.exc_info()
    # Catch any error while parsing dirPath
    except:
        print "Failed to parse " + dirPath
        print "Error message:\n",sys.exc_info()

