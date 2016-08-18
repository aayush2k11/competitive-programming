s = raw_input()
count = 1
for letter in s:
  if letter >= 'A' and letter <= 'Z':
    count += 1
print count