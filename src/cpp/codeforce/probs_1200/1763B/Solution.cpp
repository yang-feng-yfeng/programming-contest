#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> a(n, make_pair(0LL, 0LL));
	vector<ll> revMin(n);
	rep(i, 0, n-1) {
		cin >> a[i].first;
	}
	rep(i, 0, n-1) {
		cin >> a[i].second;
	}
	sort(a.begin(), a.end());

	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) {
			revMin[i] = a[i].second;
		} else {
			revMin[i] = min(revMin[i+1], a[i].second);
		}
	}
	
	ll ksum = k;
	auto it = upper_bound(a.begin(), a.end(), make_pair(ksum, LLONG_MAX));
	while (it != a.end()) {
		int idx = it - a.begin();
		k -= revMin[idx];
		if (k <= 0) {
			cout << "No" << endl;
			return -1;
		}
		ksum += k;
		it = upper_bound(it, a.end(), make_pair(ksum, LLONG_MAX));
	}
	cout << "Yes" << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/