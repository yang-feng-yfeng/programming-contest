#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll convert(string input) {
	// replace
		// cout << "input1: " << input << endl;

	replace(input.begin(), input.end(), '?', '0');
	// cout << "input: " << input << endl;
	bitset<64> set(input) ;
	return set.to_ullong();
}

ll solve() {
	string s; ll N;
	cin >> s >> N;
	int n = s.size();
	rep(i, 0, n - 1) {
		if (s[i] == '?') {
			string cp = s;
			cp[i] = '1';
			ll tmp = convert(cp);
			if (N < tmp) {
				s[i] = '0';
			} else {
				s[i] = '1';
			}
		}
	}
	// cout << "s: " << s << endl;
	if (convert(s) > N) {
		return -1;
	}
	return convert(s);
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