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
	int n, k;
	cin >> n >> k;
	if ((n-1) / 2 < k) {
		cout << "-1\n";
		return 0;
	}

	vector<int> res;
	int cur = 1;
	int top = n;
	for (int i = 0; i < k; i++) {
		res.push_back(cur++);
		res.push_back(top--);
	}
	for (int i = cur; i <= top; i++) {
		res.push_back(i);
	}
	for ( auto r : res) {
		cout << r << " ";
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