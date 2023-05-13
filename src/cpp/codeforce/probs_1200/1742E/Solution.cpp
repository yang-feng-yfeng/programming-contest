#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<pair<ll, ll>> prev(n);
  rep(i, 0, n - 1) {
    cin >> a[i];
    if (i == 0) {
      prev[0] = make_pair(a[0], a[0]);
    } else {
      prev[i].first = max(prev[i - 1].first, a[i]);
	  prev[i].second = prev[i - 1].second + a[i];
    }
  }
  rep(i, 0, q - 1) {
    ll step;
    cin >> step;
    auto idx = upper_bound(prev.begin(), prev.end(), make_pair(step, LLONG_MAX));
	if (idx - prev.begin() == 0) {
		cout <<  0LL  << " ";
	} else {
		cout << prev[idx - prev.begin() - 1].second << " ";
	}

	
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
    // cout << res << endl;
  }
}
/********  Main() Ends Here *************/