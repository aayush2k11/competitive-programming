// Problem URL: https://www.hackerrank.com/challenges/two-strings

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
  int tc;
  cin >> tc;
  string s1, s2;
  while (tc--){
    cin >> s1;
    cin >> s2;
    int arr1[26] = {0}, flag=0;
    for (int i=0;i<s1.length();i++){
      arr1[s1[i]-'a']++;
    }
    for (int i=0;i<s2.length();i++){
      if (arr1[s2[i] - 'a'] > 0){
        flag = 1;
        break;
      }
    }
    cout << (flag == 1 ? "YES" : "NO") <<endl;
  }
  return 0;
}