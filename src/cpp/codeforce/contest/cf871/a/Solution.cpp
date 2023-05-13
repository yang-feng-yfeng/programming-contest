#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)
string codeforces = "codeforces";

ll solve() {
	string tmp;
	cin >> tmp;
	int res = 0;
	rep(i, 0, 9) {
		if (tmp[i] != codeforces[i]) {
			res ++;
		}
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