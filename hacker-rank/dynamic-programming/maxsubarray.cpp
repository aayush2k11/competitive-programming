// Problem URL: https://www.hackerrank.com/challenges/maxsubarray
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tc,n,flag;
    cin >> tc;
    while(tc--){
        flag=0;
        int sum=0;
        int m1, m2;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]>=0)
                flag=1;
        }
        if(!flag){
            int maxVal=arr[0];
            for(int i=1;i<n;i++){
                maxVal=max(maxVal,arr[i]);
            }
            cout <<maxVal<<" "<<maxVal<<endl;
        }
        else{
            m1=m2=0;
            for(int i=0;i<n;i++){
                if(arr[i]>=0)
                    sum+=arr[i];
                m1+=arr[i];
                if(m1<0)
                    m1=0;
                else if(m2<m1)
                    m2=m1;
            }
            cout <<m2<<" "<<sum<<endl;
        }
    }
    return 0;
}
