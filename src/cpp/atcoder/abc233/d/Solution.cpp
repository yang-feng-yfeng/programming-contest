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
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	map<ll, int> premap;
	ll presum = 0;
	premap[0] = 1;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll cur = a[i];
		presum += cur;
		if (premap[presum - k] != 0) {
			res += premap[presum - k];
		} 
		premap[presum] ++;
	}
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/