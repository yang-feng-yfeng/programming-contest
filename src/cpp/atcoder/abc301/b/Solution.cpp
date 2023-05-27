#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep (i, 0, n-1) cin >> a[i];
	vector<int> res;
	rep(i, 1, n-1) {
		res.push_back(a[i-1]);
		if (abs(a[i] - a[i-1]) != 1 ) {
			if (a[i] > a[i-1]) {
				int k = a[i-1] + 1;
				while (k < a[i]) {
					res.push_back(k++);
				}
			} else {
				int k = a[i-1] - 1;
				while (k > a[i]) {
					res.push_back(k--);
				}
			}
		}
	}
	if (n>1) res.push_back(a[n-1]);
	rep(i, 0, res.size()-1) cout << res[i] << " ";
	cout << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	ll res = solve();
	// cout << res << endl;
}
/********  Main() Ends Here *************/