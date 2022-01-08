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

int dfs(int n, ll x, vector<vector<ll>> & a, int cur) {
	if (cur >= n) {
		if ( x == 1 ) {
			return 1;
		} 
		return 0;
	}
	ll res = 0;
	// cout << "cur: " << cur << endl;
	for (int value : a[cur]) {
		if (x % value == 0) {
			res += dfs(n, (x / value), a, cur + 1);
		}
	}
	return res;
}

int solve() {
	int n;
	ll x;
	cin >> n >> x;
	vector<vector<ll>> a(n);
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		for (int j = 0; j < l; j++) {
			ll k;
			cin >> k;
			a[i].push_back(k);
		}
	}
	// cout << "init done" << endl;

	ll res = dfs(n, x, a, 0);
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
}
/********  Main() Ends Here *************/