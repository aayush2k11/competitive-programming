#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int count[n+1][k+1];
  for (int i=1;i<=n;i++){
    count[i][1] = 1;
    count[i][0] = 0;
  }
  for (int i=1;i<=k;i++){
    count[1][i] = i;
  }
  for (int i=2;i<=n;i++){
    for (int j=2;j<=k;j++){
      count[i][j] = INT_MAX;
      for (int x=1;x<=j;x++){
        int res = 1+ max(count[i-1][x-1], count[i][j-x]);
        count[i][j] = min(count[i][j], res);
      }
    }
  }
  cout << count[n][k] << endl;
  return 0;
}