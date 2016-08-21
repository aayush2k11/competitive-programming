#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
  int t, count;
  string s;
  cin >> t;
  while(t--){
    cin >> s;
    int alphabets[26] = {0};
    count = 0;
    for(int i=0;i<s.length();i++){
      if(alphabets[s[i]-'a']==0){
        alphabets[s[i]-'a'] = 1;
        count++;
      }
    }
    cout << count << endl;
  }
}
