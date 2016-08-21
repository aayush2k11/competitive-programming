// Problem URL: https://www.hackerrank.com/challenges/palindrome-index

#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
  int tc, finalIndex, l, r, checkLeft, flag;
  string s;
  cin >> tc;
  while(tc--){
    cin >> s;
    r = s.length() - 1;
    l = 0;
    while (r>l){
      if (s[l] == s[r]){
        r--;
        l++;
      } else {
        break;
      }
    }
    if (r <= l){
      cout << "-1" << endl;
    } else {
      checkLeft = l+1;
      flag = 1;
      while (checkLeft < r){
        if (s[checkLeft] == s[r]){
          r--;
          checkLeft++;
        } else {
          flag = 0;
          cout << r << endl;
          break;
        }
      }
      if (flag){
        cout << l << endl;
      }
    }
  }
}