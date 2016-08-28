// Problem URL: https://www.hackerrank.com/challenges/maximum-element
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;

int max(int a, int b){
    if (a>=b)
        return a;
    else return b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::stack<int> myStack, maxStack;
    int n, q, x, maxValue = 0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> q;
        if (q==1){
            cin >> x;
            maxValue = max(x,maxValue);
            myStack.push(x);
            maxStack.push(maxValue);
        } else if (q==2){
            if (myStack.size()>0){
                myStack.pop();
                maxStack.pop();
                maxValue = maxStack.size() == 0 ? 0 : maxStack.top();
            }
        } else if (q==3){
            cout << maxStack.top() << endl;
        }

    }
    return 0;
}
