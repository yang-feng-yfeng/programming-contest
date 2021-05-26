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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, k;
		cin >> n >> k;  
		vector<int> a(n);
		for (int i = 0; i < n ; i++) {
			cin >> a[i];
		}
		
		ll res = 0;
		map<int, int> remaindCnt;
		int mx = 0;
		// vector<int> remaindCnt(k, 0); // the number with remainder 0 at 0, 1 at 1 .., k-1 at k-1
		for (int i = 0; i < n; i++) {
			if (a[i] % k == 0) continue;
			remaindCnt[a[i] % k] ++;
			mx = max (mx, remaindCnt[a[i] % k]);
		}

		// int max = 0;
		int minIdx = k;

		// for (int i = 1; i < k ; i++) {
		// 	if (max < remaindCnt[i]) {
		// 		max = remaindCnt[i];
		// 		minIdx = i;
		// 	}
		// }
		for (auto [key, value] : remaindCnt) {
			if (value == mx) {
				minIdx = min(minIdx, key);
			}
		}
		res = mx == 0 ? 0 : ( mx - 1) * 1ll * k + (k - minIdx) + 1;
		cout << res << endl;
	}
	
}
/********  Main() Ends Here *************/