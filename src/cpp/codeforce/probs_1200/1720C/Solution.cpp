#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	int count = 0;
	int doubleConnected = 0;
	string tmp;
	rep(i, 0, n-1) {
		cin >> tmp;
		rep(j, 0, m-1) {
			a[i][j] = tmp[j] == '0' ? 0 : 1;
			if (a[i][j] == 1) {
				count ++;
			} else {
				 if (i >= 1) {
					if (a[i-1][j] == 0) {
						doubleConnected++;
					} 
				 }
				 if (j >= 1) {
					if (a[i][j-1] == 0) {
						doubleConnected++;
					}
				 }
				 if (i >= 1 && j >= 1) {
					if (a[i-1][j-1] == 0) {
						doubleConnected++;
					}
				 }
				 if (i >= 1 && j < m-1) {
					if (a[i-1][j+1] == 0) {
						doubleConnected++;
					}
				 }
			}
		}
	}
	if (doubleConnected > 0) {
		return count ;
	} else {
		if (count == n * m) {
			return count - 2;
		} else {
 			return count  - 1;
		}
	}
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