#!/usr/bin/python
import sys
file = open(sys.argv[1],'r')
word = "true"
count = 0
total = 0
for line in file:
    total = total + 1
    if word not in line:
        count = count + 1
print count/float(total)
