#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll calcOneRow(vector<ll>& a, int size) {
    sort(a.begin(), a.end());
    // cout << "sort done" << endl;
    ll res = 0LL;
    ll preSum = 0LL + a[0];
    rep(i, 1, size -1) {
      res += i * static_cast<ll>(a[i]) - preSum;
      preSum += static_cast<ll>(a[i]);
    }
    return res;
}

ll solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<ll>> a(m, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[j][i];
    }
  }
  ll res = 0LL;
  rep(i, 0, m-1) {
    res += calcOneRow(a[i], n);
  }
  return res;
}

/********** Main()  function *******/
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/