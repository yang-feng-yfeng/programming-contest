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
ll mod = 998244353;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<ll> dp(10);

	// init 
	for (int i = 0; i < 10; i++) {
		if (i == a[0]) {
			dp[i] = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		vector<ll> dp2(10);
		for (int j = 0; j < 10; j++) {
			int f = (a[i] + j) % 10;
			int g = (a[i] * j) % 10;
			dp2[f] = (dp2[f] + dp[j]) % mod;
			dp2[g] = (dp2[g] + dp[j]) % mod;
		}
		dp = dp2;
	}

	for (int i = 0; i < 10; i++) {
		cout << dp[i] << endl;
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/