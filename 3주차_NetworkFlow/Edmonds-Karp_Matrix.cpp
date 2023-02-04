const int MAX_V = 1000; //max of number of vertices
const int INF = 1<<30;

int v; //number of vertices
int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int maximum_flow(int s, int t){
  memset(flow, 0, sizeof(flow));
  int ret = 0;
  while(1){
    vector<int> parent(MAX_V, -1);
    queue<int> q;
    parent[s] = s;
    q.push(s);
    while(!q.empty() && ~parent[t]){
      int cur = q.front();
      q.pop();
      for (int next = 0; next < v; next++){
        if (cap[cur][next] > flow[cur][next] && ~parent[next]){
          q.push(next);
          parent[next] = cur;
        }
      }
      if (~parent[s]) break;
      int new_flow = INF;
      
      for (int i = s; i != t; i = parent[i]) new_flow = min(cap[parent[i]][i] - flow[parent[i]][i], new_flow);

      for (int i = s; i != t; i = parent[i]){
        flow[parent[i]][i] += new_flow;
        flow[i][parent[i]] -= new_flow;
      }

      ret += new_flow;
    }
  }
  return ret;
}
