#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, W;
  cin >> n >> W;
  int value[n], weight[n];
  for (int i=0;i<n;i++)
    cin >> value[i];
  for (int i=0;i<n;i++)
    cin >> weight[i];
  int k[n+1][W+1];
  for (int i=0;i<=n;i++){
    for (int j=0;j<=W;j++){
      if (i==0 || j==0)
        k[i][j]=0;
      else if (weight[i-1]<=W){
        k[i][j] = max(value[i-1] + k[i-1][j-weight[i-1]], k[i-1][j]);
      } else {
        k[i][j] = k[i-1][j];
      }
    }
  }
  cout << k[n][W] << endl;
  return 0;
}