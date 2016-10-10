#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int cost[n][m];
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++)
      cin >> cost[i][j];
  }
  int totalCost[n][m];
  totalCost[0][0] = cost[0][0];
  for (int i=1;i<n;i++)
    totalCost[i][0] = totalCost[i-1][0] + cost[i][0];

  for (int i=1;i<m;i++)
    totalCost[0][i] = totalCost[0][i-1] + cost[0][i];

  for (int i=1;i<n;i++){
    for (int j=1;j<m;j++){
      totalCost[i][j] = cost[i][j] + min(totalCost[i-1][j-1], min(totalCost[i-1][j], totalCost[i][j-1]));
    }
  }
  cout << totalCost[n-1][m-1] << endl;
  return 0;
}
