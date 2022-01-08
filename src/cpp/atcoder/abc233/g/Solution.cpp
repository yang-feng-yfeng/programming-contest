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

// #define DEBUG 1

int dp[51][51][51][51];
vector<string> s;

int solve(int lx, int ly, int rx, int ry) {
	if (lx > rx) {return 0;}
	if (ly > ry) {return 0;}
	if (dp[lx][ly][rx][ry] < 1000) {return dp[lx][ly][rx][ry];}
	dp[lx][ly][rx][ry] = max(ry-ly+1, rx-lx+1);
	for (int i = lx; i <= rx; i++) {
		bool ok = true;
		for (int j = ly; j <= ry; j++) {
			if (s[i][j] == '#') {
				ok = false; 
				break;
			}
		}
		if (ok) {
			dp[lx][ly][rx][ry] = min(dp[lx][ly][rx][ry], solve(lx, ly, i-1,ry) + solve(i+1, ly, rx, ry));
		}
	}

	for (int i = ly; i <= ry; i++) {
		bool ok = true;
		for (int j = lx; j <= rx; j++) {
			if (s[j][i] == '#') {
				ok = false;
				break;
			}
		}
		if (ok) {
			dp[lx][ly][rx][ry] = min(dp[lx][ly][rx][ry], solve(lx, ly, rx, i-1) + solve(lx, i + 1, rx, ry));
		}
	}
	return dp[lx][ly][rx][ry] ;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	rep(i, 0, n-1){
		rep(j, 0, n-1){
			rep(k, 0, n-1){
				rep(l, 0, n-1){
					dp[i][j][k][l] = 100000;
				}
			}
		}
	}
	#ifdef DEBUG 
		cout << "init done1" << endl;
	#endif
	s.resize(n);
	rep(i, 0, n-1) {cin >> s[i];}
	#ifdef DEBUG 
		cout << "init done" << endl;
	#endif
	cout << solve(0, 0, n-1, n-1) << "\n";
	return 0;
}
/********  Main() Ends Here *************/