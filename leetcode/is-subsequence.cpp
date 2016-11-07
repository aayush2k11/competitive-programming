#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
  string s, t;
  cin >> s >> t;
    int alphabets[26]={0};
    for (int i=0;i<t.length();i++){
      alphabets[t[i]-'a']++;
    }
    int flag = 1;
    for (int i=0;i<s.length();i++){
      alphabets[s[i]-'a']--;
    }
    for (int i=0;i<26;i++){
      if (alphabets[i]<0){
        flag = 0;
        break;
      }
    }
    if (flag)
      cout << "true" << endl;
    else cout << "false" << endl;
}