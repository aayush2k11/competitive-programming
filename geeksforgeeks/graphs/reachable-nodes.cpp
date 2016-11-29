#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> bfs(vector<int> g[], int src, int visited[], int componentValue){
  queue<int> q;
  q.push(src);
  visited[src] = componentValue;
  vector<int> reachableNodes;
  while(!q.empty()){
    int t = q.front();
    reachableNodes.push_back(t);
    q.pop();
    for (int i=0;i<g[t].size();i++){
      if (!visited[g[t][i]]){
        visited[g[t][i]] = componentValue;
        q.push(g[t][i]);
      }
    }
  }
  return reachableNodes;
}

void findReachableNodes(vector<int> g[], int n, int nodes[], int v){
  int visited[v+1];
  for (int i=0;i<=v;i++){
    visited[i] = 0;
  }
  vector<vector<int> > m[1000];
  int componentValue = 0;
  for (int i=0;i<n;i++){
    int u = nodes[i];
    if (!visited[u]){
      componentValue++;
      vector<int> neighbours = bfs(g, u, visited, componentValue);
      m[visited[u]].push_back(neighbours);
    }

    vector<int> xyz = m[visited[u]][0];
    for (int i=0; i<xyz.size(); i++){
      cout << xyz[i] << " ";
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
  cout << "Enter edges: " << endl;
  for (int i=0;i<edge;i++){
    cin >> x >> y;
    graph[x].push_back(y);
  }
  int n;
  cout << "Enter number of nodes: ";
  cin >> n;
  int nodes[n];
  cout << "enter nodes: " << endl;
  for (int i=0;i<n;i++){
    cin >> nodes[i];
  }
  findReachableNodes(graph, n, nodes, vertices);
  return 0;
}