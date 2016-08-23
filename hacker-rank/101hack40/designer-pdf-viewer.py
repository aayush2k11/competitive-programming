heights = map(int, raw_input().split())
strings = raw_input().split()
count = 0
for s in strings:
  maxHeight = 0
  length = len(s)
  for i in s:
    maxHeight = max(heights[ord(i)-ord('a')], maxHeight)
  count += maxHeight*length
print count