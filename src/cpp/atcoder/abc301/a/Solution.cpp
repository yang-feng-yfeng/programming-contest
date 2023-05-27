#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

string solve() {
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0, ind = 0;
	while (a + b < n && a < n/ 2 && b < n/2) {
		if (s[ind] == 'T') {
			a ++;
			ind ++;
		} else if (s[ind] == 'A') {
			b++;
			ind ++;
		}
	}

	return (a > b) ? "T" : "A";
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	// int T;
	// cin >> T;
	// for (int t = 0; t < T ; t++) {
		string res = solve();
		cout << res << endl;
	// }
}
/********  Main() Ends Here *************/