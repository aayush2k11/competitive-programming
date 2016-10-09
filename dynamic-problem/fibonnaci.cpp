#include <cstdio>
#include <iostream>
#define LL long long int
using namespace std;
int main(){
  int n;
  cin >> n;
  LL fib[n+1];
  fib[0]=fib[1] = 1;
  fib[2] = 1;
  for (int i=3;i<=n;i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
  cout << fib[n] << endl;
  return 0;
}