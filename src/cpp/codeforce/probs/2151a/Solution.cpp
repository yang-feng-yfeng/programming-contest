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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	rep(i, 0, m-1) {
		cin >> a[i];
	}
	if (m == 1) {
		return n - a[0] + 1;
	} else {
		bool alwaysBigger = true;
		rep(i, 0, m-2) {
			if (a[i] >= a[i+1]) {
				alwaysBigger = false;
				break;
			}
		}
		if (alwaysBigger) {
			return n - a[m-1] + 1;
		} else {
			return 1;
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