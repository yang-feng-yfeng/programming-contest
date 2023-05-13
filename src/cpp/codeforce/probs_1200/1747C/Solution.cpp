#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	// A 0, X B  --> B win
	// B X, 1 A  --> B win
	// A 1, X B  --> B win 
	// B X, 2 A  --> B win
	// A 2, X B  --> B win
	// B X, has 3 A --> B win
	// A 3, X B -> B win


	int n;
	cin >> n;
	vector<int> a(n);
	int minA = INT_MAX;
	rep(i, 0, n-1) {
		cin >> a[i];
		if (i > 0) {
			minA = min(a[i], minA);
		}
	}

	if (a[0] > minA) {
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
	}
	return 0;
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
		//cout << res << endl;
	}
}
/********  Main() Ends Here *************/