#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<ll> preSum(n + 1, 0);
	rep(i,0,n-1) {
		cin >> a[i];
		if (i == 0) {
			preSum[i+1] = a[i];
		} else {
			preSum[i+1] = a[i] + preSum[i];
		}
	}
	int ops = 30;
	// do binary search
	int left = 0, right = n-1;
	while (ops > 0) {
		if (left < right) {
			int mid = left + (right - left) / 2;
			cout << "? " << (mid - left) + 1 << " ";
			rep (i, left, mid) {
				cout << i+1 << " ";
			}
			cout << endl;
			cout.flush();
			ll output; cin >> output;
			if (output > (preSum[mid+1] - preSum[left])) {
				right = mid;
			} else {
				left = mid + 1;
			}
		} else {
			cout <<  "! " << left+1 << endl;
			cout.flush();
			return 1;
		}
		ops--;
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
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/