#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string probableMatch(string typed, string phrase){
  int l1 = typed.length();
  int l2 = phrase.length();
  string ans = "";
  int j=0;
  for (int i = 0; i<l2;i++){
    if (j>= l1)
      break;
    if (j<l1 && typed[j] == ' ')
      j++;
    if (phrase[i] >= 'a' && phrase[i] <= 'z'){
      if (phrase[i] == typed[j])
        j++;
      else {
        ans += phrase[i];
      }
    }
  }
  if (ans == "")
    return "UNMATCHED";
  return ans;
}

int main(){
  string typed, phrase;
  getline(cin, typed);
  getline(cin, phrase);
  cout << probableMatch(typed, phrase) << endl;
  return 0;
}