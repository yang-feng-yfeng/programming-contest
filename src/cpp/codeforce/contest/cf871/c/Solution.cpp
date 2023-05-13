#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	int book01 = INT_MAX, book10 = INT_MAX , book11 = INT_MAX;
	int t, tmp;
	rep(i, 0, n-1) {
		cin >> t >> tmp;
		if (tmp == 10) {
			book10 = min(book10, t);
		} else if (tmp == 1) {
			book01 = min(book01, t);
		} else if (tmp == 11) {
			book11 = min(book11, t);
		}
	}

	if (book11 == INT_MAX && (book01 == INT_MAX || book10 == INT_MAX) ) {
		return -1;
	}
	if (book11 == INT_MAX) {
		return book10 + book01;
	} else if (book01 == INT_MAX || book10 == INT_MAX) {
		return book11;
	}

	return min(book11, book10 + book01);
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