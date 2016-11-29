#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

vector<int> shortesPath(vector<pair<int, int> > g[], int src, int V){
  set<pair<int, int> > visitedNodes;
  vector<int> dist(V, INF);

  dist[src] = 0;
  visitedNodes.insert(make_pair(0, src));
  while(!visitedNodes.empty()){
    pair<int, int> temp = *visitedNodes.begin();
    visitedNodes.erase(visitedNodes.begin());
    int u = temp.second;

    pair<int, int> adjacent;
    for(int i = 0; i < g[u].size(); i++){
      adjacent = g[u][i];
      int v = adjacent.first;
      int w = adjacent.second;
      if (dist[v] > dist[u] + w ){
        if(dist[v]!= INF){
          visitedNodes.erase(visitedNodes.find(make_pair(dist[v], v)));
        }
        dist[v] = dist[u] + w;
        visitedNodes.insert(make_pair(dist[v], v));
      }
    }
  }
  return dist;
}


int getMinEdgeReversal(vector<pair<int, int> > g[], int edges[][2], int E, int src, int dest, int V){
  vector<int> dist = shortesPath(g, src, V);
  if (dist[dest] == INF) return -1;
  else return dist[dest];
}

int main(){
  int vertices, edges;
  cin >> vertices;
  vector<pair<int, int> > graph[10005];
  cin >> edges;
  cout << " Number of edges: " << edges << endl;
  int edge[edges][2];
  cout << "Enter edges" << endl;
  for (int i=0;i<edges; i++){
    cin >> edge[i][0] >> edge[i][1];
    graph[edge[i][0]].push_back(make_pair(edge[i][1], 0));
    graph[edge[i][1]].push_back(make_pair(edge[i][0], 1));
  }
  int src, dest;
  cout << "enter source and destination" << endl;
  cin >> src >> dest;
  cout << getMinEdgeReversal(graph, edge, edges, src, dest, vertices) << endl;
  return 0;
}