#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	// ll sum = 0ll;
	rep(i, 0, n - 1)
	{
		cin >> a[i];
		// sum += a[i];
	}
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	ll res = 1;
	ll cur = 0;
	rep(i, 0, n-2) {
		cur += a[i], sum -= a[i];
		res = max( res, __gcd(sum, cur));
	}
	return res; // Not found anything in common, so return 1 as possible minimum GCD
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		ll res = solve();
		cout << res << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/