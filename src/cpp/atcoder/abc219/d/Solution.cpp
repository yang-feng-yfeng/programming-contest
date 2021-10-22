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

int solve() {
	int n, x, y; 
	cin >> n >> x >> y;
	vector<vector<int>> dp(305, vector<int>(305, 0x3F3F3F3F));
	vector<pair<int, int>> ab(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ab[i] = make_pair(a, b);
	}

	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int l = x; l >= 0; l--) {
			for (int k = y; k >= 0; k--) {
				dp[l][k] = min(dp[l][k], (dp[max(0, l - ab[i].first)][max(0, k - ab[i].second)] + 1));
			}
		}
	}

	return dp[x][y] >= 0x3F3F3F3F ? -1 : dp[x][y];
}

/********** Main()  function *******/
int main()
{
	int res = solve();
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/