const int MAX_V = 52; //max of number of vertices
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
        }
      }
      if (parent[t] == -1) break; //s -> t의 경로가 없는 경우 break한다.
      int new_flow = INF;
      
      for (int i = t; i != s; i = parent[i]) new_flow = min(cap[parent[i]][i] - flow[parent[i]][i], new_flow);

      for (int i = t; i != s; i = parent[i]){
        flow[parent[i]][i] += new_flow;
        flow[i][parent[i]] -= new_flow;
      }

      ret += new_flow;
    }
  }
  return ret;
}
