#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	// vector<int> a(n);
	int mSum =0, bSum = 0;
	int tmp;
	rep(i, 0, n-1) {
		cin >> tmp;
		if (tmp % 2 == 0) {
			mSum += tmp;
		} else {
			bSum += tmp;
		}
	}
	if (mSum > bSum) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	cout << endl;
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