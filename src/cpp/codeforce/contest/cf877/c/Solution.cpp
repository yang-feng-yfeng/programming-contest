#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n, m;
	cin >> n >> m;
	if (n % 2 == 0) {
		// start with n-1, until 1
		for (int i = n-1; i >= 1; i-=2) {
			for (int j = 1; j <= m; j++) {
				cout << (i-1) * m + j << " ";
			}
			cout << endl;
		}
		// start with n, until 2
		for (int i = n; i >= 2; i-=2) {
			for (int j = 1; j <= m; j++) {
				cout << (i-1) * m + j << " ";
			}
			cout << endl;
		}
	} else {
		// start with n, until 1
		for (int i = n; i >= 1; i-=2) {
			for (int j = 1; j <= m; j++) {
				cout << (i-1) * m + j << " ";
			}
			cout << endl;
		}
		// start with n-1, until 2
		for (int i = n-1; i >= 2; i-=2) {
			for (int j = 1; j <= m; j++) {
				cout << (i-1) * m + j << " ";
			}
			cout << endl;
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