#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, 0, n-1) {
		cin >> p[i];
	}

	int a = -1, b= 1;

	rep(i, 1, n-1) {
		if (p[i] > p[b]) {
			b = i;
		}
	}

	b--;
	if (p[b] < p[0] && b == n-2) {
		// Case 4 2 1 3
		cout << p[n-1] << " ";
		rep (i, 0, n-2) {
			cout << p[i] << " ";
		}
		cout << endl;
		return 0;
	}

	for (int i = b; i > 0; i--) {
		if (p[i-1] < p[0]) {
			a = i;
			break;
		}
	}
	if (a == -1) a = 0;
	vector<int> res;
	rep(i, b+1, n-1) {
		res.push_back(p[i]);
	}

	for (int i = b; i>= a; i--) {
		res.push_back(p[i]);
	}

	rep(i, 0, a-1) {
		res.push_back(p[i]);
	}

	rep(i, 0, n-1) {
		cout << res[i] << " ";
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