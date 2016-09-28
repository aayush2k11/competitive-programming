// Problem URL: https://www.hackerrank.com/contests/moodysuniversityhackathon/challenges/small-risk-trading
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  float probability[n], profit[n], loss[n], effective[n];
  for (int i=0;i<n;i++){
    cin >> probability[i];
  }
  for (int i=0;i<n;i++){
    cin >> profit[i];
  }
  for (int i=0;i<n;i++){
    cin >> loss[i];
  }
  for (int i=0;i<n;i++){
    effective[i] = probability[i]*profit[i] - ((1-probability[i])*loss[i]);
  }
  sort(effective, effective+n);
  int lastIndex = n-k;
  float bestVal = 0.00;
  for (int i=lastIndex;i<n;i++){
    if (effective[i] >= 0.00)
    bestVal+=effective[i];
  }
  cout << std::fixed;
  cout << std::setprecision(2);
  cout << bestVal << endl;
}