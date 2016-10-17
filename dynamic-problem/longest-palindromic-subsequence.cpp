#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  cout << n<<endl;
  int LPS[n][n];
  for (int i=0;i<n;i++)
    LPS[i][i]=1;
  for (int cl=2;cl<=n;cl++){
    for (int i=0;i<n-cl+1;i++){
      int j = i+cl-1;
      if (s[i]==s[j] && cl==2){
        LPS[i][j]=2;
      } else if (s[i]==s[j]){
        LPS[i][j] = LPS[i+1][j-1] + 2;
      } else {
        LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1]);
      }
    }
  }
  cout << LPS[0][n-1] << endl;
  return 0;
}