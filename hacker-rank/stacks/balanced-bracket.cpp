// Problem URL: https://www.hackerrank.com/challenges/balanced-brackets
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
  int tc;
  string bracket;
  cin >> tc;
  while(tc--){
    cin >> bracket;
    int flag = 0;
    std::stack<char> myStack;
    for(int i=0;i<bracket.length();i++){
      if (bracket[i]== '(' || bracket[i] == '[' || bracket[i] == '{')
        myStack.push(bracket[i]);
      else{
        if (bracket[i] == ')'){
          if (myStack.size() > 0 && myStack.top() == '(')
            myStack.pop();
          else{
            flag = 1;
            break;
          }
        } else if (bracket[i] == ']'){
          if (myStack.size() > 0 && myStack.top() == '[')
            myStack.pop();
          else{
            flag = 1;
            break;
          }
        } else if (bracket[i] == '}'){
          if (myStack.size() > 0 && myStack.top() == '{')
            myStack.pop();
          else{
            flag = 1;
            break;
          }
        }
      }
    }
    if (myStack.size() != 0) flag = 1;
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
  return 0;
}