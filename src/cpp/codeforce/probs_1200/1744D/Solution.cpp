#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

int logTwo(ll a) {
	int res = 0;
	while (a % 2 == 0) {
		res ++;
		a /= 2;
	}
	return res;
}

ll solve() {
	int n; cin >> n;
	ll a;

	int tmp = 0;
	rep(i, 0, n-1) {
		cin >> a;
		tmp += logTwo(a);
	}

	int logTwoN = static_cast<int>(log2(n));
	int res = 0;
	int tmpCount = 1;
	while (logTwoN > 0 && tmp < n) {
		tmp += logTwoN;
		tmpCount --;
		if (tmpCount == 0) {
			logTwoN --;
			tmpCount = (n / (1 << logTwoN)) - (n / (1 << (logTwoN + 1)));
			// cout << "logTwoN: " << logTwoN <<  " temp Count : " << tmpCount << endl;
		}
		res++;
	}
	return (tmp >= n) ? res: -1;
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