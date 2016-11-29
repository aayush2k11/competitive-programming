#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
struct node {
  int value, level;
};

int minOperations(int x, int y){
  node n = {x, 0};
  queue<node> q;
  set<int> visit;
  q.push(n);
  while(!q.empty()){
    node t = q.front();
    q.pop();
    if (t.value == y)
      return t.level;
    visit.insert(t.value);
    if (t.value*2 == y || t.value-1 == y)
      return t.level + 1;
    if (visit.find(t.value*2) == visit.end()){
      // visit(t.value*2)
      n.value = t.value*2;
      n.level = t.level+1;
      q.push(n);
    }
    if (t.value-1 >=0 && visit.find(t.value-1) == visit.end()){
      n.level = t.level+1;
      n.value = t.value-1;
      q.push(n);
    }
  }
}

int main(){
  int x, y;
  cin >> x >> y;
  cout << minOperations(x, y) << endl;
  return 0;
}