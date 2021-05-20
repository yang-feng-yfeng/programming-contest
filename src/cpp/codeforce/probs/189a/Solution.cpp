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
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	// vector<int> l{a, b, c};
	// sort(l.begin(), l.end());
	vector<int> dp(n+1, -1);
	dp[n] = 0;
	for (int i = n; i >= 0; i--) {
		if (dp[i] == -1) {
			continue;
		}
		if (i - a >= 0)
			dp[i-a] = max (dp[i-a], dp[i] + 1);
		if (i - b >= 0) 
			dp[i-b] = max(dp[i-b], dp[i] + 1);
		if (i - c >= 0) 
			dp[i-c] = max (dp[i-c], dp[i] + 1);
		// cout << "dp[i] : " << i << " : " << dp[i] << endl;
	}
	cout << dp[0] << endl;
}
/********  Main() Ends Here *************/