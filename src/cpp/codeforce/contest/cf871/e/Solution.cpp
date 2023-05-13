#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
pair<int, int> dir[] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0),
                        make_pair(0, -1)};

ll bfs(int i, int j, vector<vector<int>>& deep, set<pair<int, int>>& passed,
       ll sum) {
  if (deep[i][j] > 0 && passed.find(make_pair(i, j)) == passed.end()) {
    sum += deep[i][j];
	passed.emplace(make_pair(i, j));
    rep(k, 0, 3) {
      auto cur = dir[k];
      int newI = i + cur.first, newJ = j + cur.second;
      if (newI >= 0 && newI < deep.size() && newJ >= 0 &&
          newJ < deep[0].size()) {
        sum += bfs(newI, newJ, deep, passed, 0);
      }
    }
  }
  return sum;
}

ll solve() {
  int n, m;
  cin >> n >> m;
  ll res = 0;
  set<pair<int, int>> passed;
  vector<vector<int>> deep(n, vector<int>(m));

  rep(i, 0, n - 1) {
    rep(j, 0, m - 1) { cin >> deep[i][j]; }
  }

  rep(i, 0, n - 1) {
    rep(j, 0, m - 1) {
      if (deep[i][j] > 0 && passed.find(make_pair(i, j)) == passed.end()) {
        ll sum = bfs(i, j, deep, passed, 0);
        res = max(res, sum);
      }
    }
  }
  return res;
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