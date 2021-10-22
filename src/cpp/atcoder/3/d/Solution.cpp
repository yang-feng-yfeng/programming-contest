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
ll mod=1e9+7;

ll solve(int n, vector<ll> numbs) {
	vector<vector<ll>> dp(n + 1, vector<ll>(n+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			} 
			if (numbs[i] % j == 0) {
				dp[i][j] += (dp[i - 1][j - 1]) % mod;
 			}
			cout << "dp[i][j] : " << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res = (res + dp[n][i]) % mod;
	}
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<ll> numbs(n);
	for (int i = 0; i < n; i++) {
		cin >> numbs[i];
	}
	solve(n, numbs);
}
/********  Main() Ends Here *************/