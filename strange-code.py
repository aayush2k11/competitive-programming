#!/bin/python
# problem URL: https://www.hackerrank.com/challenges/strange-code
import sys
import math

t = int(raw_input().strip())
n = int(math.log(t/3 + 1, 2))
previous = 3*(2**n - 1)
remainder = t - previous
next = 3*(2**n)
ans = next - remainder + 1
print ans
