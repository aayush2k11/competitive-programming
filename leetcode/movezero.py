nums = [0, 1, 0, 3, 12]
size1 = len(nums)
nums2 = []
for i in range(len(nums)):
	print('i: ', i, ' ,len(nums): ', len(nums))
	if nums[i] == 0:
		nums.pop(i)
size2 = len(nums)
diff = size1 - size2
for i in range(diff):
	nums.append(0)
print(nums)
