#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

int solve() {
  int n;
  ll m;
  cin >> n >> m;

  ll res = m / static_cast<ll>(n);
  ll left = m % static_cast<ll>(n);

  if (res == 0) {
    cout << "No" << endl;
    return -1;
  }

  if (n % 2 == 1 || (n - left) % 2 == 0 || left == 0) {
    cout << "Yes" << endl;
    if (n % 2 == 1) {
      rep(i, 0, n - 1) {
        if (i < n - 1) {
          cout << res << " ";
        } else {
          cout << res + left << " ";
        }
      }
    } else {
      rep(i, 0, n - 1) {
        if (i < n - 2) {
          cout << res << " ";
        } else {
          cout << res + left / 2 << " ";
        }
      }
    }
    cout << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return -1;
  }
}

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
    // cout << res << endl;
  }
}
/********  Main() Ends Here *************/