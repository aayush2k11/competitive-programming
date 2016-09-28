// Problem URL: https://www.hackerrank.com/contests/moodysuniversityhackathon/challenges/learning-from-the-past
#include <cstdio>
#include <iostream>
using namespace std;

int max(int a, int b){
  if (a>b)
    return a;
  else return b;
}

int main(){
  int n, maxVal=0, x, y, z, max2;
  cin >> n;
  for (int i=0;i<n;i++){
    cin >> x >> y >> z;
    int max1 = max(max(x,y), z);
    if (max1 == x){
      max2 = max(y,z);
    } else if (max1 == y){
      max2 = max(x,z);
    } else {
      max2 = max(x,y);
    }
    maxVal = max(max1+max2, maxVal);
  }
  cout << maxVal << endl;
}