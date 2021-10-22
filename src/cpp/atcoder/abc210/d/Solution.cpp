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
	ll h, w, c;
	cin >> h >> w >> c;
	vector<vector<ll>> a(h, vector<ll>(w));
	// vector<vector<ll>> plus(h, vector<ll>(w));
	// vector<vector<ll>> minus(h, vector<ll>(w));
	vector<vector<ll>> plus;
	vector<vector<ll>> minus;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			plus.emplace_back(vector<ll>{a[i][j], a[i][j] + (i + j) * c, i, j});
			minus.emplace_back(vector<ll>{a[i][j], (- a[i][j] + (i + j) * c), i, j});
		}
	}
	// minimum of plus - maximumm of minus if not the same position, and 
	
	sort(plus.rbegin(), plus.rend());
	sort(minus.begin(), minus.end());
	ll res = 1e15;
	int n = h * w;

	int topHeight = min(1000, n);
	for (int i = 0; i < topHeight; i++) {
		for (int j = 0; j < topHeight; j++) {
			int firstIdx = plus[i][3] + plus[i][2];
			int secondIdx = minus[i][3] + minus[i][2];
			if (firstIdx > secondIdx) {
				res = min(res, plus[i][1] - minus[i][1]);
			} 
		}
	}
	cout << res << "\n";


	// iterate over every point,
	// then iterate over all distance from 1 -> to h + w
	// if for the next distance, the c * dis + Ao >= max of previous distance, break
	// set<pair<int,int>> visited;
	// int diff = maxi - mini;
	// int maxiDis = ceil((long double) 1.0 * diff / c);
	// ll res = 1e12;

	// for (int i = 0; i < h; i++) {
	// 	for (int j = 0; j < w; j++) {
	// 		visited.insert(make_pair(i, j));
	// 		for (int d = 1; d <= maxiDis; d++) {
	// 			ll diffd = (ll)d * c;
	// 			if (d != 1) {
	// 				if (diffd + a[i][j] > res) {
	// 					break;
	// 				}
	// 			}
	// 			for (int l = 0; l < h; l++) {
	// 				for (int m = 0; m < w; m++) {
	// 					if (visited.find(make_pair(i, j)) != visited.end()) {
	// 						int man = abs((long) l - i) + abs((long) m - j);
	// 						if (man == d) {
	// 							res = min (res, ((ll) a[l][m] + diffd + a[i][j]));
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }

}
/********  Main() Ends Here *************/