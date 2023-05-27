#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
ll p = 998244353;

ll solve() {
	string s; cin >> s;
	int firstLow = -1, lastLow = -1;
	int countQ = 0;
	int n = s.size();
	
	rep(i, 0, n-1) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (firstLow == -1) firstLow = i;
			lastLow = i;
		}
		else if (s[i] == '?') {
			countQ ++;
		}
	}
	if (firstLow == -1) {
		ll res = 1;
		while (countQ > 0) {

		}
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	ll res = solve();
	cout << res << endl;
}
/********  Main() Ends Here *************/