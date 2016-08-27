// Problem URL: https://www.hackerrank.com/challenges/2d-array
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
  int max_sum = -99999, sum=0;
  int array[6][6];
  for(int i =0;i<6;i++){
    for(int j=0;j<6;j++){
      cin >> array[i][j];
    }
  }
  for (int i=0;i<=3;i++){
    for(int j=0;j<=3;j++){
      sum = array[i][j] + array[i][j+1] + array[i][j+2] + array[i+1][j+1] + array[i+2][j] + array[i+2][j+1] + array[i+2][j+2];
      max_sum = max(sum, max_sum);
    }
  }
  cout << max_sum << endl;
}