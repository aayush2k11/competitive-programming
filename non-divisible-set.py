n,k = map(int, raw_input().split())
nums = map(int , raw_input().split())
count = 0
for i in range (n-1):
  for j in range(i+1, n):
    if (nums[i] + nums[j]) % k !=0:
      count += 1
print count