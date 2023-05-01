#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll dfs(ll a, ll b, ll x, ll l, ll r) {
  if (b == a) return 0;
  if (abs(b - a) >= x) return 1;
  if (b > a) {
    if (b + x <= r) {
      return 2;
    } else {
      if (a - x >= l) {
        return 2;
      }
      if (a + x <= r && b - x >= l) {
        return 3;
      }
    }
    return -1;
  } else {
    return dfs(b, a, x, l, r);
  }
}

ll solve() {
  ll l, r, x, a, b;
  cin >> l >> r >> x >> a >> b;

  if (abs(b - a) >= x) {
    return 1;
  } else {
    ll res = dfs(a, b, x, l, r);
    return res;
  }
  return 0;
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