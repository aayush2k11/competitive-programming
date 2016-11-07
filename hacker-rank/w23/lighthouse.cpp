#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int min(int a, int b){
  if (a<=b)
    return a;
  else return b;
}
int main(){
  int n;
  cin >> n;
  string tree[50];
  int count[50][50] = {0}, maxCount = 0;
  for (int i=0;i<n;i++){
    cin >> tree[i];
  }
  int top=0, left=0, right=0, bottom=0;
  if (tree[n/2][n/2]!= '.')
    cout << 0 << endl;
  else {
    int i = n/2-1;
    while (i>=0 && tree[i][n/2] == '.'){
      top++;
      i--;
    }
    i = n/2+1;
    while (i<n && tree[i][n/2] == '.'){
      bottom++;
      i++;
    }
    i = n/2-1;
    while (i>=0 && tree[n/2][i] == '.'){
      left++;
      i--;
    }
    i = n/2+1;
    while(i<n && tree[n/2][i] == '.'){
      right++;
      i++;
    }
    maxCount = min(top, min(bottom, min(left, right)));
    cout << maxCount << endl;
  }
  return 0;
}