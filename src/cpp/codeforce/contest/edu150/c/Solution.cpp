#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
const int value[] = {1, 10, 100, 1000, 10000};

ll solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> dp(5, vector<int>(2, -2e9-1));
  dp[0][0] = 0;

  for (int i = n - 1; i >= 0; i--) {
    int cur = s[i] - 'A';
    vector<vector<int>> newDp(5, vector<int>(2, -2e9-1));
    for (int mx = 0; mx < 5; mx++) {
      for (int have = 0; have < 2; have++) {
        for (int next = 0; next < 5; next++) {
          int newMx = max(mx, next);
          int newHave = have + (next != cur);
          int newValue = dp[mx][have] + (next < mx ? -1 : 1) * value[next];
          if (newHave < 2) {
            newDp[newMx][newHave] = max(newDp[newMx][newHave], newValue);
          }
        }
      }
    }
    dp = newDp;
  }
  int res = -2e9-1;
  rep(i, 0, 4) {
    rep(j, 0, 1) { res = max(res, dp[i][j]); }
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