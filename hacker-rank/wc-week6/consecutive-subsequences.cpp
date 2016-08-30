// Problem URL: https://www.hackerrank.com/contests/w6/challenges/consecutive-subsequences
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int tc, n, sum, k;
  cin >> tc;
  while(tc--){
    cin >> n >> k;
    int arr[n];
    sum = 0;
    int count[100] = {0};
    count[0] = 1;
    for(int i=0;i<n;i++){
      cin >> arr[i];
      sum = (sum + arr[i])%k;
      count[sum]++;
    }
    long long ans = 0;
    for(int i=0;i<k;i++){
      ans += (long long)count[i]*(count[i]-1)/2;
    }
    cout << ans << endl;
  }
  return 0;
}
