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


int solve(int n, int k, string s) {
	// dp[i][j] = dp[cur position][last * digit] = * count
	// dp[i][j] = min(dp[i-1][j - k], dp[i-1][j-k+1], ... dp[i-1][j-1]) + 1
	// 			= min (dp[i-1][j])
	// vector<vector<int>> dp(n+1, vector<int> (n+1, n+1));
	vector<int> dp(n+1, 1e6);
	int lastStar = -1;
	dp[0] = 0;
	int firstStar = 0;

	for(int i=0;i<n;i++){
        if(s[i]=='*'){
			firstStar = i;
			dp[i+1] = 1;
            break;
        }
        dp[i+1]=0;
		// cout << "dp1[" << i+1 << "]: " << dp[i+1] << endl;
    }
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			for (int j = 1; j <= k && i + 1 - j >firstStar; j++) {
				dp[i+1] = min(dp[i+1], dp[i + 1-j] + 1);
				// cout << "j: " << j << endl;
				// cout << "dp[" << i+1 << "]: " << dp[i+1] << endl;
			}
			for (int j = i-1; j > lastStar; j--) {
				dp[j+1] = dp[i+1];
			}
			lastStar = i;
		} 
	}
	return dp[lastStar+1];
}

/********** Main()  function *******/
int main()
{
	int T, N, K;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		string s;
		cin >> N >> K >> s;
		int res = solve(N, K, s);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/