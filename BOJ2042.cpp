#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> tree;
ll high = 1;

ll getval(ll node, ll nl, ll nr, ll fl, ll fr){
  if (fl <= nl && nr <= fr) return tree[node];
  if (nr < fl || fr < nl) return 0;
  ll mid = (nl + nr)/2;
  ll lv = getval(node*2, nl, mid, fl, fr);
  ll rv = getval(node*2+1, mid+1, nr, fl, fr);
  return lv+rv;
}

void update(ll idx, ll value){
  ll i = high+idx-1;
  tree[i] = value;
  for (ll j = i/2; j; j/=2){
    tree[j] = tree[j*2] + tree[j*2+1];
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  while(high < n) high<<=1;
  tree.resize(high<<1);
  
  for (ll i = 0; i < n; i++) cin >> tree[high+i];
  
  for (ll i = high-1; i; i--){
    tree[i] = tree[i*2] + tree[i*2+1];
  }
  
  for (ll i = 0; i < m+k; i++){
    ll x, y, z;
    cin >> x >> y >> z;
    if (x == 1) update(y, z); 
    else cout << getval(1, 1, high, y, z) << "\n";
  }
}
