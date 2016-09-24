// Problem URL: https://www.hackerrank.com/challenges/red-john-is-back
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int main(){
  int combinations[41] = {0};
  for (int i=1;i<=3;i++){
    combinations[i] = 1;
  }
  combinations[4] = 2;
  for (int i=5;i<=40;i++){
    combinations[i] = combinations[i-1] + combinations[i-4];
  }
  int primes[217287] = {1};
  primes[0] = primes[1] = 0;
  for(int i=2;i<217287;i++){
    primes[i] = 1;
  }
  for (int i=2;i<217287;i++){
    if (primes[i]==1){
      int x = i+i;
      while (x < 217287){
        primes[x] = 0;
        x+=i;
      }
    }
  }
  int tc, n;
  cin >> tc;
  while (tc--){
    cin >> n;
    int comb = combinations[n];
    int count =0;
    for(int i=2;i<=comb;i++){
      if (primes[i]==1){
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}