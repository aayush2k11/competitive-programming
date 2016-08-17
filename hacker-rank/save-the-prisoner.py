# Enter your code here. Read input from STDIN. Print output to STDOUT
# Problem URL: https://www.hackerrank.com/challenges/save-the-prisoner
tc = int(raw_input())
for i in range(tc):
    n,m,s = map(int, raw_input().split())
    if n == 1:
        print 1
    elif (s+m-1)%n == 0:
        print n
    else:
        print (s+m-1)%n
