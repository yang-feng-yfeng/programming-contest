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
	int n;
	cin >> n;
	vector<int> a(n+1);
	rep(i, 1, n) {
		cin >> a[i];
	}
	vector<deque<int>> q(n+1);
	vector<int> dp(n+1, 0);
	rep(i, 1, n) {
		dp[i] = dp[i-1];
		q[a[i]].emplace_back(i);
		if (q[a[i]].size() > a[i]) q[a[i]].pop_front();
		if (q[a[i]].size() == a[i]) dp[i] = max(dp[i], dp[q[a[i]].front()-1] + a[i]); 
	}
	return dp[n];
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