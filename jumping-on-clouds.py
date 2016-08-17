#!/bin/python
# problem URL: https://www.hackerrank.com/challenges/jumping-on-the-clouds

import sys


n = int(raw_input().strip())
c = map(int,raw_input().strip().split(' '))
count = 0
i = 0
while i < n-1:
    if i+2 < n:
        if c[i+2] == 1:
            i += 1
        else:
            i += 2
        count += 1
    else:
        i += 1
        count +=1
print count
        
