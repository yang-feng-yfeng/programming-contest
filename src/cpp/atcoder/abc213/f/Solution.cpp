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
	string s;
	cin >> s;

	vector<int> dp(n+1, 0);

	vector<int> res(n, 0);
	// dp store f(Si, S0), f(Si, S1), f(Si, S2)..., i starts from n 
	for (int i = 0; i < n; i++) {
		dp[i] = s[n - 1] == s[i] ? 1 : 0;
		// cout << "dp0: " << dp[i] << endl;
		res[0] += dp[i];
	}

	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			dp[i] = (s[n - k] == s[i]) ? (dp[i+1] + 1) : 0;
			res[k - 1] += dp[i];
		}	
	}
	
	reverse(res.begin(), res.end());
	for (int i : res) {
		cout << i << "\n";
	}
}
/********  Main() Ends Here *************/