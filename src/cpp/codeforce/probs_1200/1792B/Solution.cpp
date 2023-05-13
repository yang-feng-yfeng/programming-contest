#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	ll a,b ,c, d;
	cin >> a >> b >> c >> d;
	if (a > 0) {
		return a + min(b, c) * 2 + min (a + 1, abs (c - b) + d);
	} else {
		return 1;
	}
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