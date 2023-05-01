#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i, 0, n-1) {
		cin >> a[i];
		ll temp = a[i];
		int pos = 0;
		while (temp > 0) {
			temp = temp >> 1;
			// cout <<  " temp: " << temp << endl;
			pos ++;
		}
		b[i] = (1 << pos) - a[i];
		// cout << " (1 << pos) : " << (1 << pos) << endl;
	}

	cout << n << endl;
	rep(i, 0, n-1) {
		cout << (i+1) << " " << b[i] << endl;
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