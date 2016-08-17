#!/mport sys
# Problem URL: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
c = map(int,raw_input().strip().split(' '))
E = 99
if c[(k)%n] == 1:
    E = 97
i = (k)%n
while i != 0:
    E -= 1
    if c[(i+k)%n] == 1:
        E -= 2
    i = (i+k)%n
print E

