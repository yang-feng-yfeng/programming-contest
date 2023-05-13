#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n), ap(n);
  rep(i, 0, n - 1) cin >> a[i];
  rep(i, 0, n - 1) cin >> ap[i];
  int l = 0, r = n - 1;
  int resL = -1, resR = n;
  while (l < r && (resL == -1 || resR == n)) {
    if (a[l] == ap[l]) {
      l++;
    } else if (a[r] == ap[r]) {
      r--;
    } else if (a[l] != ap[l] && resL == -1) {
      for (int lf = l - 1; lf >= 0; lf--) {
        if (ap[lf] > ap[lf + 1]) {
          resL = lf + 1;
          break;
        }
      }
      resL = max(resL, 0);
    } else if (a[r] != ap[r] && resR == n) {
      for (int rf = r + 1; rf <= n - 1; rf++) {
        if (ap[rf] < ap[rf - 1]) {
          resR = rf - 1;
          break;
        }
      }
      resR = min(resR, n - 1);
    }
  }
  if (l >= r) {
    cout << 1 << " " << n << endl;
  } else {
    cout << resL + 1 << " " << resR + 1 << endl;
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
    // cout << res << endl;
  }
}
/********  Main() Ends Here *************/