# Problem URL: https://www.hackerrank.com/challenges/alternating-characters
tc = int(raw_input())
while tc:
    s = raw_input()
    count = 0
    i = 0
    while i < len(s):
        j = i+1
        while j < len(s) and s[j] == s[i]:
            count += 1
            j+=1
        i = j
    print count