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
	int h, w;
	cin >> h >> w;
	vector<int> direct {-1, 0, 1, 0, -1, -1, 1, 1, -1};
	vector<vector<int>> res(h, vector<int>(w, 0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || j == 0 || i == h-1 || j == w-1) {
				bool shouldPut = true;
				for (int k = 0; k < 8; k++) {
					int newi = i + direct[k];
					int newj = j + direct[k+1];
					if (newi >= 0 && newi < h && newj >= 0 && newj < w) {
						if (res[newi][newj] == 1) {
							shouldPut = false;
							break;
						}
					}
				}
				if (shouldPut) {
					res[i][j] = 1;
				}
			}
			
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << res[i][j];
		}
		cout << "\n";
	}
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