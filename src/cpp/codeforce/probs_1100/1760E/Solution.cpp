#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> prev(n, 0);  // count of prev 1
  vector<ll> suiv(n, 0);  // count of suiv 0
  rep(i, 0, n - 1) {
    cin >> a[i];
    if (i == 1) {
      prev[i] = a[i - 1];
    } else if (i > 1) {
      prev[i] = prev[i - 1] + a[i - 1];
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 2) {
      suiv[i] = a[i + 1] == 0 ? 1 : 0;
    } else if (i < n - 2) {
      suiv[i] = suiv[i + 1] + (a[i + 1] == 0 ? 1 : 0);
    }
  }

  ll res = 0;
  ll maxDiff = 0;
  rep(i, 0, n - 1) {
    if (a[i] == 1) {
      res += suiv[i];

      // Diff calculation, 1 -> 0;
      maxDiff = max(maxDiff, -suiv[i] + prev[i]);
    } else {
      // Diff calculation, 0 -> 1;
      maxDiff = max(maxDiff, +suiv[i] - prev[i]);
    }
  }

  return (maxDiff > 0) ? res + maxDiff : res;
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