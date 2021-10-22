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
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<int> s(n), t(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> t[i];

	vector<int> dp(n);
	dp[0] = t[0];
	for (int i = 1; i < n; i++) {
		dp[i] = min(t[i], dp[i-1] + s[i-1]);
	}

	while (dp[n-1] + s[n-1] < dp[0]) {
		dp[0] = dp[n-1] + s[n-1];
		for (int i = 1; i < n; i++) {
			dp[i] = min(t[i], dp[i-1] + s[i-1]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dp[i] << "\n";
	}
	return 0;
}
/********  Main() Ends Here *************/