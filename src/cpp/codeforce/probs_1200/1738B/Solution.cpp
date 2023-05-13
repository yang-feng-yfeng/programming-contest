#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(k);
	rep(i, 0, k-1) {
		cin >> a[i]; 
	}

	ll tmpMin = LLONG_MAX;
	for(int i = k -1 ; i > 0; i--) {
		ll tmpI = a[i] - a[i-1];
		if (tmpI > tmpMin) {
			cout << "No" << endl;
			return -1;
		} else {
			tmpMin = tmpI;
		}
	}

	// first prev: a[0]
	// n - k + 1
	if (tmpMin * (n - k + 1) >= a[0] || k == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
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
		//cout << res << endl;
	}
}
/********  Main() Ends Here *************/