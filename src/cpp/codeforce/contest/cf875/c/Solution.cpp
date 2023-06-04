#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

const int NMAX = 2e5 + 10;
int dp[NMAX];
vector<pair<int, int>> g[NMAX];

void dfs(int u, int cur) {
  for (auto e : g[u]) {
    int v = e.first;
    int idx = e.second;
    if (dp[v] == 0) {
      dp[v] = dp[u] + (idx <= cur);
      dfs(v, idx);
    }
  }
}

ll solve() {
  int n;
  cin >> n;
  // clean up
  rep(i, 1, n) {
    dp[i] = 0;
    g[i].clear();
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  dp[1] = 1;
  dfs(1, 0);
  int ans = 0;
  rep(i, 1, n) {
	ans = max(ans, dp[i]); }
  return ans;
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/