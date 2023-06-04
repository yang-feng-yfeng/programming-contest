#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<int> ac(2*n + 1), bc(2*n + 1);
	rep(i, 0, n-1) {
		cin >> a[i];
	}
	rep(i, 0, n-1) {
		cin >> b[i];
	}
	int tmp = 1; int tmpb = 1;
	rep(i, 1, n-1) {
		if (a[i] == a[i-1]) {
			tmp++;
		} else {
			ac[a[i-1] - 1] = max(tmp, ac[a[i-1] - 1]);
			tmp = 1;
		}
		if (b[i] == b[i-1]) {
			tmpb ++;
		} else {
			bc[b[i-1] -1] = max(tmpb, bc[b[i-1] -1]);
			tmpb = 1;
		}
	}
	ac[a[n-1] - 1] = max(tmp, ac[a[n-1] - 1]);
	bc[b[n-1] - 1] = max(tmpb, bc[b[n-1] - 1]);
	int res = 0;
	rep(i, 0, 2* n) {
		res = max(res, ac[i] + bc[i]);
	}
	return res;
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
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/