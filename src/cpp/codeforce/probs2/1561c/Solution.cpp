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
	vector<pair<int,int>> caves(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int res = 0;
		int cur = 0;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			res = max(res, a - cur);
			cur++;
		}
		caves[i] = make_pair(res, k);
	}

	sort(caves.begin(), caves.end());
	int res = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, caves[i].first - cur);
		cur += caves[i].second;
	}
	return res + 1;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << res << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/