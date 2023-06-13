#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	vector<int> p(n);
	int oneIdx=-1, twoIdx=-1,maxIdx=-1;
	rep(i, 0, n-1) {
		cin >> p[i];
		if (p[i] == 1) {
			oneIdx = i;
		}
		if (p[i] == 2) {
			twoIdx = i;
		}
		if (p[i] == n) {
			maxIdx = i;
		}
	}
	// put n between 1 and 2;
	if (oneIdx < twoIdx) {
		if (oneIdx < maxIdx && maxIdx < twoIdx) {
			cout << "1 1" << endl;
		} else if (oneIdx > maxIdx) {
			cout << oneIdx + 1 << " " << maxIdx + 1  << endl;
		} else if (maxIdx > twoIdx) {
			cout << twoIdx + 1 << " " << maxIdx + 1 << endl;
		}
	} else {
		if (twoIdx < maxIdx && maxIdx < oneIdx) {
			cout << "1 1" << endl;
		} else if (twoIdx > maxIdx) {
			cout << twoIdx + 1 << " " << maxIdx + 1  << endl;
		} else if (maxIdx > oneIdx) {
			cout << oneIdx + 1 << " " << maxIdx + 1 << endl;
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