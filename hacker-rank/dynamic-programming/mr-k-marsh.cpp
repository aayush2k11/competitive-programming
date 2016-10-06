#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int m, n;
  cin >> m >> n;
  string marsh[500];
  int upper[m][n], left[m][n];
  for (int i=0;i<m;i++){
    cin >> marsh[i];
  }
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      if (i==0){
        if (marsh[i][j] == '.'){
          upper[i][j] = 0;
        } else upper[i][j] = -1;
      } else {
        if (marsh[i][j] == '.'){
          upper[i][j] = 1 + upper[i-1][j];
        } else {
          upper[i][j] = -1;
        }
      }
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (i==0){
        if (marsh[j][i] == '.'){
          left[j][i] = 0;
        } else left[j][i] = -1;
      } else {
        if (marsh[j][i] == '.'){
          left[j][i] = 1 + left[j][i-1];
        } else {
          left[j][i] = -1;
        }
      }
    }
  }
  int maxSum = 0;
  for (int i=m-1;i>=0;i--){
    for (int j=n-1;j>=0;j--){
      if (upper[i][j] > 0 && left[i][j] >0){
        int val=0;
        if (i== m-1){
          if (j==0){
            if (upper[i-1][j]!= -1 && left[i][j+1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          } else if (j==n-1){
            if (upper[i-1][j]!= -1 && left[i][j-1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          } else {
            if (upper[i-1][j]!=-1 && left[i][j-1]!=-1 && left[i][j+1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          }
        } else if (i==0){
          if (j==0){
            if (upper[i+1][j]!= -1 && left[i][j+1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          } else if (j==n-1){
            if (upper[i+1][j]!= -1 && left[i][j-1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          } else {
            if (upper[i+1][j]!=-1 && left[i][j-1]!=-1 && left[i][j+1]!=-1)
              val = 2 * (upper[i][j] + left[i][j]);
          }
        } else {
          if (upper[i-1][j]!=-1 && upper[i+1][j]!=-1 && left[i][j-1]!=-1 && left[i][j+1]!=-1)
            val = 2 * (upper[i][j] + left[i][j]);
        }
        if (val > maxSum)
          maxSum = val;
      }
    }
  }
  if (maxSum == 0)
    cout << "impossible" << endl;
  else cout << maxSum << endl;
  return 0;
}