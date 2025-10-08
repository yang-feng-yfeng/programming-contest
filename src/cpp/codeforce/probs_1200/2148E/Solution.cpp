#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unordered_map>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), targ(n+1, 0);
	rep(i, 0, n-1) {
		cin >> a[i];
		targ[a[i]]++;
	}

	rep(i, 1, n) {
		if (targ[i] % k != 0) {
			return 0;
		} else {
			targ[i] = targ[i] / k;
		}
	}

	ll res = 0;
	vector<int> tmp(n+1, 0);
	for (int l = 0, r = 0; r >= l and r < n; r++) {
		tmp[a[r]]++;
		while (tmp[a[r]] > targ[a[r]]) {
			tmp[a[l]]--;
			l++;
		}
		res += (r - l + 1);
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