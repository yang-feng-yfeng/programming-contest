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

int solve(int n, vector<vector<int>>& ab) {
	sort(ab.begin(), ab.end());
	// for (int i = 1; i < n; i++) {
	// 	if (ab[i][1] >= ab[i-1][1] && dp[i-1][1] != INT_MAX) {
	// 		dp[i][1] = dp[i-1][1] + (ab[i][1] == ab[i-1][1] ? 0 : 1);
	// 	} else {
	// 		dp[i][1] = INT_MAX;
	// 		// dp[i][0] = min(dp[i-1][1] +  (ab[i][0] == ab[i-1][1] ? 0 : 1), dp[i-1][0] + (ab[i][]))
	// 	}
	// 	if (dp[i-1][1] != INT_MAX) {
	// 		dp[i][0] = min(dp[i][0], dp[i-1][1] +  (ab[i][0] == ab[i-1][1] ? 0 : 1));
	// 	}
	// 	dp[i][0] = min(dp[i][0], dp[i-1][0] + (ab[i][0] == ab[i-1][0] ? 0 : 1));
	// }
	// return min(dp[n-1][0], dp[n-1][1]);

	int res = 0;
	res = ab[0][1];
	for (int i = 1; i < n; i ++) {
		if (ab[i][1] >= res) {
			res = ab[i][1];
		} else {
			res = ab[i][0];
		}
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> ab(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> ab[i][0] >> ab[i][1];
	}
	int res = solve(n, ab);
	cout << res << endl;
}
/********  Main() Ends Here *************/