#!/bin/python
# Problem URL: https://www.hackerrank.com/challenges/mars-exploration
import sys


S = raw_input().strip()
message = "SOS"
count = 0
for i in range(len(S)):
    if S[i] != message[i%3]:
        count+=1
print count