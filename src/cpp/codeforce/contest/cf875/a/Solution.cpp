#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int k = 1 + n;

  rep(i, 0, n - 1) {
    cin >> a[i];
    cout << k - a[i] << " ";
  }
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
    //cout << res << endl;
  }
}
/********  Main() Ends Here *************/