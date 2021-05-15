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

using namespace std;

void solve(int n) {
	if (n == 2) {
		cout << -1 << endl;
		return;
	}

	int cur = 1;
	vector<vector<int>> res(n, vector<int>(n, 0));
	for (int i = 0; i < 2 * n; i++) {
		int rown = (i % 2 == 0)? i/2 : -(i+1)/2; // 0, -1, 1, -2, 2...
		for (int j = 0; j < n; j++) {
			if (j + rown >= 0 && j + rown < n) {
				res[j + rown][j] = cur++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) {
				cout << res[i][j];
			} else {
				cout << " " << res[i][j];
			}
		}
		cout << endl;
	}
}

/********** Main()  function *******/
int main()
{
	int T;
	int n;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> n;
		solve(n);
	}
}
/********  Main() Ends Here *************/