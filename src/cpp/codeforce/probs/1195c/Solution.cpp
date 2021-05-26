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

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
	vector<vector<int>> h(N, vector<int>(2));
	for (int i = 0; i < N ; i++) {
		cin >> h[i][0];
	}
	for (int i = 0; i < N; i++) {
		cin >> h[i][1];
	}
	dp[0][0] = h[0][0];
	dp[0][1] = h[0][1];
	for (int i = 1; i < N ; i++) {
		dp[i][0] = max(dp[i][0], h[i][0] + dp[i-1][1]);
		dp[i][1] = max(dp[i][1], h[i][1] + dp[i-1][0]);
		if (i > 1) {
			dp[i][0] = max(dp[i][0], h[i][0] + dp[i-2][1]);
			dp[i][1] = max(dp[i][1], h[i][1] + dp[i-2][0]);
		}
	}
	cout << max(dp[N-1][0], dp[N-1][1]) << endl;
}
/********  Main() Ends Here *************/