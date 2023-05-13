#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n - 1) { cin >> a[i]; }

  if (n < 3) {
    cout << "Yes" << endl;
    return 0;
  }

  rep(i, 0, n-1-2) {
	int tmp = __gcd(a[i], a[i+2]);
	if (a[i+1] % tmp != 0) {
		cout << "No" << endl;
		return -1;
	}
  }

  cout << "Yes" << endl;

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