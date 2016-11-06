#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, q, p, t, count=0;
  int prevTime = -1, prevMax, prevIndex = 0;
  cin >> n;

  int order[n][2];

  for (int i=0;i<n;i++){
    cin >> q;
    if (q==1){
      cin >>  order[count][0] >> order[count][1];
      count++;
    } else if(q==2){
      cin >> t;
      int maxTime = max(t-60, 0);
      int maxValue = -1;
      maxTime = max(maxTime, prevTime);
      if (t == prevTime){
        cout << prevMax << endl;
      } else {
        if (prevTime == -1)
          prevTime = t;
        else maxValue = prevMax;
        int temp = prevIndex;
        for(int j=temp;j<count;j++){
          if(order[j][1] >= maxTime && order[j][1]<= t){
            maxValue = max(maxValue, order[j][0]);
            if (order[j][0] == maxValue){
              prevIndex = j;
            }
          }
        }
        cout << maxValue << endl;
        prevTime = t;
        prevMax = maxValue;
      }
    }
  }
  return 0;
}