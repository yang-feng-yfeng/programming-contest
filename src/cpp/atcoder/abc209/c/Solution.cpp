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
ll mod = 1e9+7;

int solve(int n, vector<int> & c) {
	ll res = 1;
	for (int i = 0; i < n; i++) {
		if (c[i] >= i) {
			res = (res * (c[i] - i) % mod);
		} else {
			res = 0;
		}
	}
	cout << res << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<int> c(N);
	for (int i = 0; i < N ; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	solve(N, c);
	return 0;

}
/********  Main() Ends Here *************/