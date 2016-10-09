#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  string one, two;
  cin >> one >> two;
  int n,m;
  n= one.size();
  m = two.size();

  int dp[n+1][m+1];
  for (int i=0;i<=n;i++){
    for (int j=0;j<=n;j++){
      if(i==0){
        dp[i][j]=j;
      } else if (j==0){
        dp[i][j]=i;
      } else {
        dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
      }
    }
  }
  cout << dp[n][m] << endl;
}