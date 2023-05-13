#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

bool findGold(ll n, ll m) {
  if (n == m) return true;
  if (n < m) return false;

  if (n % 3 == 0) {
    return findGold(n / 3, m) || findGold((n * 2) / 3, m);
  }
  return false;
}

ll solve() {
  ll n, m;
  cin >> n >> m;
  if (findGold(n, m)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
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