#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n,q;
	cin >> n >> q;
	vector<ll> preSum(n + 1, 0);
	ll tmp;
	rep(i,0,n-1) {
		cin >> tmp;
		if (i == 0) {
			preSum[i + 1] = tmp;
		} else {
			preSum[i + 1] = tmp + preSum[i];
		}
	}

	rep(i, 0, q-1) {
		int l, r;
		ll k;
		cin >> l >> r >> k;
		ll qSum = preSum[n] - (preSum[r] - preSum[l-1]) + ( r - l + 1) * k;
		if (qSum % 2 == 1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
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