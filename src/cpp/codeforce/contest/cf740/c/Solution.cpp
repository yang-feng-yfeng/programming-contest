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
	int n ;
	cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int b;
			cin >> b;
			a[0].push_back(b);
		}
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int cur = 0;
		int k = 0;
		for (int e : a[i]) {
			cur = max(cur, e + 1 - k);
			k++;
		}	
		b[i] = cur;
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
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/