#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int coin[m];
  for (int i=0;i<m;i++){
    cin >> coin[i];
  }
  int count[n+1][m];
  for (int i=0;i<m;i++){
    count[0][i] = 1;
  }
  for (int i=1;i<=n;i++){
    for (int j=0;j<m;j++){
      int x = (i-coin[j]>=0) ? count[i-coin[j]][j] : 0;
      int y = (j>=1) ? count[i][j-1] : 0;
      count[i][j] = x+y;
    }
  }
  cout << count[n][m-1] << endl;
  return 0;
}