#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n1 = 1e9 + 7;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	ll n; cin >> n;
	ll res = 0;
	res = (n * (n+1) % n1) * (4 * n -1) %n1 * 337 %n1;
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