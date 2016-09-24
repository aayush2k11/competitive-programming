// Problem URL: https://www.hackerrank.com/challenges/mandragora
#include <cstdio>
#include <iostream>
#include <algorithm>

#define LL long long int

using namespace std;
int main(){
  int tc, n;
  cin >> tc;
  for(int i=0;i<tc;i++){
    cin >> n;
    LL arr[n];
    LL sum =0;
    for (int i=0;i<n;i++){
      cin >> arr[i];
      sum+=arr[i];
    }
    sort(arr, arr+n);
    LL P=sum, var =0, S=1;
    for (int i=0;i<n;i++){
      S++;
      sum-=arr[i];
      var = S*sum;
      if (var>P){
        P = var;
      }
    }
    cout << P << endl;
  }
  return 0;
}