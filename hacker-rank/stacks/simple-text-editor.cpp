// Problem URL: https://www.hackerrank.com/challenges/simple-text-editor
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
  int tc, q, index;
  std::stack<string> myStack;
  string temp, first = "", input;
  cin >> tc;
  while(tc--){
    cin >> q;
    if (q==1){
      cin >> input;
      if (myStack.size()==0){
        myStack.push(input);
      } else {
        temp = myStack.top() + input;
        myStack.push(temp);
      }
    } else if(q==2){
      cin >> index;
      temp = myStack.top().substr(0, myStack.top().length() - index);
      myStack.push(temp);
    } else if(q==3){
      cin >> index;
      cout << myStack.top()[index-1] << endl;
    } else if (q==4){
      myStack.pop();
    }
  }
  return 0;
}