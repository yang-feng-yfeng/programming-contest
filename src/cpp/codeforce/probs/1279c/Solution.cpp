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
#include <unordered_set>

using namespace std;
using ll = long long;

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int m;
		int n;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		int first = 0;
		int second = 0;
		ll res = 0;
		unordered_set<int> seen;
		while (second < m) {
			// find b[second]
			while (first < n && a[first] != b[second]) {
				seen.emplace(a[first]);
				first++;
			}
			res += 2 * (first - second) + 1;
			second++;
			while (second < m && seen.find(b[second]) != seen.end()) {
				// found
				res += 1;
				second++;
			}
		}
		cout << res << endl;
	}
	
}
/********  Main() Ends Here *************/