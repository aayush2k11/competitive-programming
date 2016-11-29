#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<int> graph[], vector<int> indegree, int v){
  vector<int> topolgical;
  queue<int> q;

  for (int i=0;i<v;i++){
    if (indegree[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int t = q.front();
    q.pop();
    topolgical.push_back(t);
    for (int i=0;i<graph[t].size();i++){
      cout << graph[t][i] << " ";
      indegree[graph[t][i]]--;
      if (indegree[graph[t][i]] == 0){
        q.push(graph[t][i]);
      }
    }
  }
  return topolgical;
}

void maximumEdgeAddtion(vector<int> graph[], vector<int> indegree, int v){
  bool visited[v];
  for (int i=0;i<v;i++)
    visited[i] = false;
  vector<int> topo = topologicalSort(graph, indegree, v);

  for (int i=0;i<topo.size();i++){
    int t = topo[i];
    for (int j=0;j<graph[t].size();j++){
      visited[j] = true;
    }

    for (int j=i+1;j<topo.size();j++){
      if (visited[topo[j]] == false){
        cout << t << "-" << topo[j] << " ";
      }
      visited[topo[j]] = false;
    }
    cout << endl;
  }
}


int main(){
  int vertices, edge;
  vector <int> graph[10005];
  cout << "Enter number of vertices: " << endl;
  cin >> vertices;
  cout << "Enter number of edges: " << endl;
  cin >> edge;
  int x, y;
  vector<int> indegree;
  for (int i=0;i<vertices;i++){
    indegree.push_back(0);
  }
  cout << "Enter edges: " << endl;
  for (int i=0;i<edge;i++){
    cin >> x >> y;
    graph[x].push_back(y);
    indegree[y]++;
  }
  maximumEdgeAddtion(graph, indegree, vertices);
  return 0;
}