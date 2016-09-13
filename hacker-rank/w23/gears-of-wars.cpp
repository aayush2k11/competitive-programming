// Problem URL https://www.hackerrank.com/contests/w23/challenges/gears-of-war
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q, n;
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> n;
        if (n%2==1)
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
