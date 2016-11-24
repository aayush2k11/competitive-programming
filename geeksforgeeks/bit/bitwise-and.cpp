#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
int msbPos(ll n){
  int msb = -1;
  while(n){
    n = n>>1;
    msb++;
  }
  return msb;
}

ll findBitSum(ll x, ll y){
  ll sum = 0;
  while (x && y){
    int msb_x = msbPos(x);
    int msb_y = msbPos(y);
    if (msb_x != msb_y)
      return sum;
    else {
      ll msb_val = 1<<msb_x;
      sum += msb_val;
      x -= msb_val;
      y -= msb_val;
    }
  }
  return sum;
}

int main(){
  ll x, y;
  cin >> x >> y;
  cout << findBitSum(x, y) << endl;
  return 0;
}