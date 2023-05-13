#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

int solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int res = n - 1;

	int tmp = 0;
	rep(i, 0, n-1) {
		if (i > 1) {
			if (str[i] == str[i-2]) {
				tmp ++;
			} else {
				res -= tmp;
				tmp = 0;
			}
		}
	}

	return res - tmp;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/