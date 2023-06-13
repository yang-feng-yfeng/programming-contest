#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int q;
  cin >> q;
  string res = "";
  ll first = INT_MIN, last = INT_MIN;
  bool beautified = false;
  rep(i, 1, q) {
    ll tmp;
    cin >> tmp;
    if (i == 1) {
      res += '1';
      first = tmp;
      last = tmp;
    } else {
      if (beautified) {
        if (tmp >= last && tmp <= first) {
          res += '1';
          last = tmp;
        } else {
          res += '0';
        }
      } else {
        if (tmp >= last) {
          res += '1';
          last = tmp;
        } else if (tmp < last && tmp <= first) {
          beautified = true;
          res += '1';
          last = tmp;
        } else {
			res += '0';
		}
      }
    }
  }
  cout << res << endl;
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