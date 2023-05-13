#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> d(n);
  vector<int> a(n, 0);
  rep(i, 0, n - 1) { cin >> d[i]; }
  rep(i, 0, n - 1) {
    if (i == 0) {
      a[i] = d[i];
    } else {
      if (a[i - 1] - d[i] >= 0 && d[i] != 0) {
        return -1;
      }
      a[i] = a[i - 1] + d[i];
      // cout << "test a[i] " << a[i] << " ";
    }
  }
  rep(i, 0, n - 1) { cout << a[i] << " "; }
  cout << endl;
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
    if (res == -1) {
      cout << res << endl;
    }
  }
}
/********  Main() Ends Here *************/