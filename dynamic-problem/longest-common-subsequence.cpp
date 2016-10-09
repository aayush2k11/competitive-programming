#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int lcs(string a, string b, int n, int m){
  if (n==0 || m==0){
    return 0;
  }
  if (a[n] == b[m])
    return 1 + lcs(a,b,n-1,m-1);
  else return max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
}
int main(){
  string one, two;
  cin >> one >> two;
  int n,m;
  n = one.size();
  m = two.size();
  cout << lcs(one,two,n,m);
}