#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 52;
const int INF = 1<<30;

int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int maximum_flow(int s, int t){
  memset(flow, 0, sizeof(flow));
  int ret = 0;
  while(1){
    vector<int> parent(MAX_V, -1);
    queue<int> q;
    parent[s] = s;
    q.push(s);
    
    while(!q.empty() && parent[t] == -1){
      int cur = q.front();
      q.pop();
      for (int next = 0; next < MAX_V; next++){
        if (cap[cur][next] - flow[cur][next] > 0 && parent[next] == -1){
          q.push(next);
          parent[next] = cur;
          if (next == t) break;
        }
      }
    }
    if (parent[t] == -1) break;
    int new_flow = INF;
      
    for (int i = t; i != s; i = parent[i]) new_flow = min(cap[parent[i]][i] - flow[parent[i]][i], new_flow);
    for (int i = t; i != s; i = parent[i]){
      flow[parent[i]][i] += new_flow;
      flow[i][parent[i]] -= new_flow;
    }

    ret += new_flow;
  }
  return ret;
}

int ctoi(char c){
  return c <= 'Z' ? c - 'A' : c - 'a' + 26;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  memset(cap, 0, sizeof(cap));
  int e;
  cin >> e;
  for (int i = 0; i < e; i++){
    char u, v;
    int c;
    cin >> u >> v >> c;
    cap[ctoi(u)][ctoi(v)] += c;
    cap[ctoi(v)][ctoi(u)] += c;
  }
  cout << maximum_flow(0, 25);
}
