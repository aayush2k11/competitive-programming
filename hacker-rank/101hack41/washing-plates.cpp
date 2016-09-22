// Problem URL:https://www.hackerrank.com/contests/101hack41/challenges/washing-plates
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  long int income = 0;
  long int total = 0;
  long int additions[n];
  long int add[n], ded[n];
  for (int i=0;i<n;i++){
    cin >> add[i] >> ded[i];
    additions[i] = add[i] + ded[i];
    income -= ded[i];
    total += add[i];
  }
  sort(additions, additions+n, std::greater<int>());
  if (k>=n){
    cout << total << endl;
  } else {
    for (int i=0;i<k;i++){
      income += additions[i];
    }
    cout << income << endl;
  }
  return 0;
}