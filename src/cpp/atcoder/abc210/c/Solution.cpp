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
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	unordered_map<int, int> cnt;
	for (int i = 0; i < k; i++) {
		cnt[c[i]]++;
	}
	int res = cnt.size();

	for (int i = k; i < n; i++) {
		cnt[c[i]] ++;
		cnt[c[i-k]]--;
		if (cnt[c[i-k]] == 0) {
			cnt.erase(c[i-k]);
		}
		res = max(res, (int)cnt.size());
	}
	cout << res << "\n";
}
/********  Main() Ends Here *************/