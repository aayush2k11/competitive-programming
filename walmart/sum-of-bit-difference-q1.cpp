#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int arr[n], sum = 0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int bitXor = arr[i]^arr[j];
      int count = 0;
      while (bitXor){
        bitXor &= (bitXor -1);
        count++;
      }
      sum += 2*count;
    }
  }
  cout << sum << endl;
  return 0;
}