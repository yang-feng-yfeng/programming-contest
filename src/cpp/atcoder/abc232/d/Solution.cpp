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
#define rep(i,l,r) for(ll i=l;i<=r;i++)

vector<string> m;
vector<vector<int>> dp;
int h, w;

int dfs(int i, int j, int cur) {
	if (i >= h || j >= w || m[i][j] == '#') {
		return cur;
	}
	if (dp[i][j] > -1) {
		return dp[i][j];
	}
	dp[i][j] = max(dfs(i+1, j, cur + 1), dfs(i, j+1, cur + 1));
	return dp[i][j];
}

int solve() {
	cin >> h >> w;
	m.resize(h);
	rep(i, 0, h-1) {cin >> m[i];}
	dp.resize(h);
	rep(i, 0, h-1) {
		dp[i].resize(w);
		rep(j, 0, w-1) {
			dp[i][j] = -1;
		}
	}
	// bfs? 
	int res = dfs(0, 0, 0);
	cout << res << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/