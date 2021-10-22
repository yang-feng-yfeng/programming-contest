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
ll mod = 998244353;

int solve() {
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n ;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<ll> curDp(3002, 0);
	vector<ll> nextDp(3002, 0);
	vector<ll> preSum(3002, 0);
	for (int i = 0; i < n; i++) {
		preSum[0] = curDp[0];
		// cout << "curDP[0] : " << curDp[0];
		for (int k = 1; k < 3002; k++) {
			preSum[k] = (preSum[k - 1] + curDp[k]) % mod;
			// cout << "curDP[k] : " << curDp[k] << endl;
			// cout << "preSUm : i: " << i << " k: " << k << " value: " << preSum[k]<< endl;
		}
		for (int j = a[i] ; j <= b[i]; j++) {
			if (i == 0) {
				nextDp[j] = 1;
				// cout << "nextDp[j] : " << nextDp[j] << " j: " << j << endl;
			} else {
				nextDp[j] = preSum[j];
				// cout << "nextDp[j] : " << nextDp[j] << " j: " << j << endl;
			}	
		}
		curDp = nextDp;
		fill(nextDp.begin(), nextDp.end(), 0);
	}
	ll res = 0;
	for (int i = 0; i < 3002; i++) {
		res = (res + curDp[i]) % mod;
	}
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/