#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	int res = 0;
	int tmp = 0;
	int last = 0;
	rep(i, 0, n-1) {
		cin >> tmp;
		if (tmp == 0) {
			last ++;
		} else {
			res = max(res, last);
			last = 0;
		}
	}
	res = max(res, last);
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