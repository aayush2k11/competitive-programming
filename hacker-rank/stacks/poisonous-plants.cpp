// Problem URL: https://www.hackerrank.com/challenges/poisonous-plants
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n, poison;
    stack<int> first, second;
    int dead = 0, iteration =0, flag = 1, firstSize, secondSize;
    cin >> n;
    while(n--){
      cin >> poison;
      first.push(poison);
    }
    int count = 0, prevCount=0;
    while(flag){
      while (first.size()>0){
        if (dead==0){
          second.push(first.top());
          first.pop();
          dead = 1;
        } else {
          if (first.top()!= -1 && second.top()!= -1 && second.top() > first.top()){
            second.pop();
            second.push(-1);
            count++;
            second.push(first.top());
            first.pop();
            dead = 0;
          } else if (first.top()== -1){
            first.pop();
          } else {
            second.push(first.top());
            first.pop();
            dead = 0;
          }
        }
      }
      if(prevCount != count){
        iteration++;
        while (second.size() > 0){
          first.push(second.top());
          second.pop();
        }
        prevCount = count;
        count =0;
        dead = 0;
      } else {
        flag = 0;
      }
    }
    cout << iteration << endl;
    return 0;
}
