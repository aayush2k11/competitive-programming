#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string getDiffString(string s){
  string shift = "";
  for(int i=1;i<s.length();i++){
    int diff = s[i]-s[i-1];
    if (diff<0)
      diff+=26;
    shift += (diff +'a');
  }
  return shift;
}

void groupShiftedStrings(string s[], int n){
  map<string, vector<int> > group;
  map<string, vector<int> >::iterator it;
  for (int i=0;i<n;i++){
    string pattern = getDiffString(s[i]);
    group[pattern].push_back(i);
  }
  for (it=group.begin(); it!=group.end(); ++it){
    vector<int> v = it->second;
    for (int i = 0;i<v.size(); i++){
      cout << s[v[i]] << " ";
    }
    cout << endl;
  }
}

int main(){
  string str[] = {"acd", "dfg", "wyz", "yab", "mop",
                    "bdfh", "a", "x", "moqs"
                   };
    int n = sizeof(str)/sizeof(str[0]);
    groupShiftedStrings(str, n);
    return 0;
}