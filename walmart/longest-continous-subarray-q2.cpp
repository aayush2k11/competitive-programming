#include <cstdio>
#include <iostream>
using namespace std;
int max(int a, int b){
  if (a>=b) return a;
  else return b;
}

int min(int a, int b){
  if (a<=b) return a;
  else return b;
}

int main(){
  int n;
  cin >> n;
  int arr[n], maxLen = 0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  for(int i=0;i<n;i++){
    int minVal = arr[i], maxVal = arr[i];
    for(int j=i+1;j<n;j++){
      minVal = min(minVal, arr[j]);
      maxVal = max(maxVal, arr[j]);
      if ((maxVal - minVal) == (j-i)){
        maxLen = max(maxLen, j-i+1);
      }
    }
  }
  cout << maxLen << endl;
  return 0;
}