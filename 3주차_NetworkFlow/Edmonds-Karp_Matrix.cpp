const int MAX_V = 1000; //number of vertices
const int INF = 1<<30; //set Infinity value which can't be value of flow (to get minimum residual capacity in path)

int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V]; //using matrix to save capacity and flow

//input : source, target(sink)
//output : maximum flow of graph
int maximum_flow(int s, int t){
  int ret = 0; //return value
  while(1){
    vector<int> parent(MAX_V, -1); //to backtrace augmenting path
    queue<int> q;
    parent[s] = s;
    q.push(s);
    
    //using bfs to find augmenting path
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
    
    if (parent[t] == -1) break; //it means there's no additional augmeting path thus have to break while loop
    
    int new_flow = INF; //initialize flow value of augmenting path
    
    //backtrace augmenting path and get minimum residual capacity in the path
    for (int i = t; i != s; i = parent[i]) new_flow = min(cap[parent[i]][i] - flow[parent[i]][i], new_flow);
    
    //increase the flow of the edge in the path
    for (int i = t; i != s; i = parent[i]){
      flow[parent[i]][i] += new_flow;
      flow[i][parent[i]] -= new_flow;
    }

    ret += new_flow;
  }
  return ret;
}
