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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// 2 pass
	vector<bool> used(n + 1, false); // 1 - n
	vector<bool> received(n+1, false);
	int start = 1;
	vector<int> res(n, 0);
	int resCnt = 0;

	// for (int i = 0; i < n; i++)
	int cur = 0;
	while ()



	// for (int i = 0; i < n; i++) {
	// 	received[a[i]] = true;
	// }

	// for (int i = 0; i < n; i++) {
	// 	if (!received[i+1]) {
	// 		if (!used[a[i]]) {
	// 			res[i] = a[i];
	// 			// cout << " res[i]: " << i << " : " << res[i] << endl;
	// 			used[a[i]] = true;
	// 			resCnt++;
	// 		}
	// 	}
		
	// }


	// for (int i = 0; i < n; i++) {
	// 	if (!used[a[i]]) {
	// 		res[i] = a[i];
	// 		used[a[i]] = true;
	// 		resCnt++;
	// 	}
	// }

	// for (int i = 0; i < n; i++) {
	// 	if (!received[i+1]) {
	// 		if (res[i] == 0) {
	// 			while (used[start]) {
	// 				start++;
	// 			}
	// 			if (i == start ) {
	// 				int k = start + 1;
	// 				while (used[k]) {
	// 					k++;
	// 				}
	// 				res[i] = k;
	// 				used[k] = true;
	// 			} else {
	// 				res[i] = start;
	// 				used[start] = true;
	// 			}
				
	// 		}
	// 	}
	// }


	// for (int i = 0; i < n; i++) {
	// 	if (res[i] == 0) {
	// 		while (used[start]) {
	// 			start++;
	// 		}
	// 		res[i] = start;
	// 		used[start] = true;
	// 	}
	// }

	cout << resCnt << "\n";
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << res[i];
		} else {
			cout << " " << res[i];
		}
	}
	cout << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/