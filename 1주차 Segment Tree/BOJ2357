#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> mintree;
vector<ll> maxtree;
ll high = 1;

ll getmin(ll node, ll nl, ll nr, ll fl, ll fr){
  if (fl <= nl && nr <= fr) return mintree[node];
  if (nr < fl || fr < nl) return 1e9+1;
  ll mid = (nl + nr)/2;
  ll lv = getmin(node*2, nl, mid, fl, fr);
  ll rv = getmin(node*2+1, mid+1, nr, fl, fr);
  return min(lv, rv);
}

ll getmax(ll node, ll nl, ll nr, ll fl, ll fr){
  if (fl <= nl && nr <= fr) return maxtree[node];
  if (nr < fl || fr < nl) return -1e9;
  ll mid = (nl + nr)/2;
  ll lv = getmax(node*2, nl, mid, fl, fr);
  ll rv = getmax(node*2+1, mid+1, nr, fl, fr);
  return max(lv, rv);
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll n, m;
  cin >> n >> m;
  while(high < n) high<<=1;
  mintree.resize(high<<1);
  
  for (ll i = 0; i < n; i++) cin >> mintree[high+i];
  maxtree = mintree;
  
  for (ll i = high-1; i; i--){
    mintree[i] = min(mintree[i*2], mintree[i*2+1]);
    maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
  }

  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    cout << getmin(1, 1, high, x, y) << " " << getmax(1, 1, high, x, y) << "\n";
  }
}
