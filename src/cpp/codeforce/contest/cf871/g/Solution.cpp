#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll squareSum(ll i, ll j, ll imin, ll jmax) {
  i = max(i, imin);
  j = min(j, jmax);
//   cout << "i : " << imin << " j : " << jmax << endl;
  return (j * (j + 1) * (2 * j + 1) / 6 - (i * (i + 1)) * (2 * i + 1) / 6);
}

ll rowToLast(ll row) { return row * (row + 1) / 2; }

ll solve() {
  ll n;
  cin >> n;

  int row;
  // find which row;
  for (int i = static_cast<int>(sqrt(n)) - 1; i <= n; i++) {
    if (rowToLast(i) < n && rowToLast(i + 1) >= n) {
      row = i + 1;
      break;
    }
  }
  // cout << "row: " << row << endl;
  int j = 1;
  ll res = 0;
  for (int i = row; i >= 1; i--, j++) {
    if (i == row) {
      res += n * n;
	//   cout << "res : " << res << endl;
    } else {
      res += squareSum(n - 1, n - 1 + j, rowToLast(i - 1),
                       rowToLast(i));
					//    cout << "res : " << res << endl;
    }
    n = n - i;
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