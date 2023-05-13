#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, 0, n-1) {
		cin >> a[i];
	}
	int l = 0, r = n-1;
	ll mn = 1, mx = n;
	while (l < r) {
		if (a[l] == mn) {
			l++;
			mn++;
		} else if (a[l] == mx) {
			l++;
			mx--;
		} else if (a[r] == mn) {
			r--;
			mn++;
		} else if (a[r] == mx) {
			r--;
			mx--;
		} else {
			break;
		}
	}

	if (l < r) {
		cout << l+1 << " " << r +1 << endl;
	} else {
		cout << -1 << endl;
	}

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