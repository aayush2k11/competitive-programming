// Problem URL: https://www.hackerrank.com/challenges/anagram
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
  int tc, count;
  string s;
  cin >> tc;
  while (tc--){
    cin >> s;
    count =0;
    if(s.length()%2 !=0){
      cout << "-1" << endl;
    } else {
      int arr1[26] = {0}, left = 0, right = s.length()/2;
      for (int i=0;i<right;i++){
        arr1[s[i]-'a']++;
      }
      for (int i=right; i<s.length();i++){
        arr1[s[i]-'a']--;
      }
      for (int i=0;i<26;i++){
        if (arr1[i]>0){
          count += arr1[i];
        }
      }
      cout << count << endl;
    }
  }
  return 0;
}