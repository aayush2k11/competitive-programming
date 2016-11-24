#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minSteps(int arr[], int n){
  int visited[n];
  int distance[n];
  vector<int> digit[10];
  vector<int>::iterator it;
  visited[0] = 0;
  for (int i=0;i<n;i++){
    visited[i] = 0;
    digit[arr[i]].push_back(i);
  }

  // for (int i=0;i<10;i++){
  //   for (it=digit[i].begin(); it != digit[i].end(); ++it){
  //     cout << *it << " ";
  //   }
  //   cout << endl;
  // }

  distance[0] = 0;
  visited[0] = 1;

  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int index = q.front();
    q.pop();

    if (index == n-1)
      break;

    int d = arr[index];
    for(it=digit[d].begin(); it != digit[d].end(); ++it){
      int nextIndex = *it;
      if (visited[nextIndex] == 0){
        visited[nextIndex] = 1;
        q.push(nextIndex);
        distance[nextIndex] = distance[index] + 1;
      }
    }
    digit[d].clear();
    if (index-1 >=0 && visited[index-1]==0){
      visited[index-1] = 1;
      distance[index-1] = distance[index] + 1;
      q.push(index-1);
    }

    if(index+1 <n && visited[index+1] == 0){
      visited[index+1] = 1;
      distance[index+1] = distance[index] + 1;
      q.push(index+1);
    }
  }
  return distance[n-1];
}

int main(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
  cout << sizeof(arr)/sizeof(arr[0]) << endl;
  cout << minSteps(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}