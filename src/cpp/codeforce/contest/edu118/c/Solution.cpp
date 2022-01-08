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

ll solve() {
	int n;
	ll h;
	cin >> n >> h;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll l = 0;
	ll r = h;

	while (l + 1 < r) {
		ll mid = (r - l) / 2 + l;
		ll res = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] + mid - 1 < a[i+1]) {
				res += mid;
			} else {
				res += a[i+1] - a[i];
			}
		}
		// cout << "res " << res << endl;
		res += mid;
		// cout << "res " << res << endl;

		if (res < h) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return r;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/