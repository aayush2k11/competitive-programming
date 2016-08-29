// Problem URL: https://www.hackerrank.com/challenges/equal-stacks
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int max(int a, int b){
    if (a>=b)
        return a;
    else return b;
}

int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];
    }
    std::stack<int> c1, c2,c3;
    c1.push(0);
    c2.push(0);
    c3.push(0);
    for(int i=n1-1;i>=0;i--){
        if (i==n1-1){
            c1.push(h1[i]);
        } else {
            c1.push(h1[i] + c1.top());
        }
    }
    for(int i=n2-1;i>=0;i--){
        if (i==n2-1){
            c2.push(h2[i]);
        } else {
            c2.push(h2[i] + c2.top());
        }
    }
    for(int i=n3-1;i>=0;i--){
        if (i==n3-1){
            c3.push(h3[i]);
        } else {
            c3.push(h3[i] + c3.top());
        }
    }
    int maxHeight = 0;
    while (c1.size()>0 && c2.size()>0 && c3.size()>0){
        int currMax = max(c1.top(), max(c2.top(), c3.top()));
        if (c1.top()==currMax && c2.top()==currMax && c3.top() == currMax){
            maxHeight = currMax;
            break;
        } else {
            while(c1.top()>=currMax){
                c1.pop();
            }
            while(c2.top()>=currMax){
                c2.pop();
            }
            while(c3.top()>=currMax){
                c3.pop();
            }
        }
    }
    cout << maxHeight;
    return 0;
}