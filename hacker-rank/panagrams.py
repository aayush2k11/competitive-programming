# Problem URL: https://www.hackerrank.com/challenges/pangrams
s = raw_input()
s = s.lower()
letters = []
for letter in s:
  if letter != ' ':
    if letter not in letters:
      letters.append(letter)
if len(letters) != 26:
  print "not pangram"
else:
  print "pangram"