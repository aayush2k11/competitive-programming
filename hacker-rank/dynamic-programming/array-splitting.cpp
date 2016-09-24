// Problem URL: https://www.hackerrank.com/challenges/array-splitting
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int findSplit(int arr[], int start, int end){
  int sum = 0, leftSum = 0;
  if (start == end){
    return 0;
  }
  for(int i=start;i<=end;i++){
    sum += arr[i];
  }
  for(int i=start;i<=end;i++){
    leftSum += arr[i];
    if (leftSum == sum-leftSum){
      return 1 + max(findSplit(arr, start, i), findSplit(arr, i+1, end));
    }
  }
  return 0;
}

int main(){
  int n,tc, allZeros = 1;;
  cin >> tc;
  for (int i=0;i<tc;i++){
    cin >> n;
    int arr[n];
    for(int j=0;j<n;j++){
      cin >> arr[j];
      if (arr[j] != 0) allZeros = 0;
    }
    if (allZeros){
      cout << n-1 << endl;
    } else {
      cout << findSplit(arr, 0, n-1) << endl;
    }
  }
  return 0;
}