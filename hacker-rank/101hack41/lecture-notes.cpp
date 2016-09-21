// Problem URL: https://www.hackerrank.com/contests/101hack41/challenges/lecture-notes
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
  int n, k, flag = 0;
  cin >> n >> k;
  string student;
  int num;
  cin >> student;
  for (int i=0;i<k;i++){
    cin >> num;
    if (student[num-1] == '0'){
      flag = 1;
    }
  }
  if (flag){
    cout << "YES" << endl;
  } else cout << "NO" << endl;
}