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

vector<vector<ll>> twoLessDiff(vector<vector<ll>> &f, vector<vector<ll>> &s) {
	ll minV = LLONG_MAX;
	ll minIdx = -1;

	ll secondMinV = LLONG_MAX;
	ll secondMinIdx = -1;

	ll fir=0, second=0;

	while (fir < f.size() &&  second < s.size()) {
		ll diff = abs(s[second][0] - f[fir][0]);
		if (diff < minV) {
			ll prev = minV;
			ll prevIdx = minIdx;
			minV = diff;
			minIdx = f[fir][1];
			secondMinV = prev;
			secondMinIdx = prevIdx;
		} else if ( diff < secondMinV ) {
			secondMinV = diff;
			secondMinIdx = f[fir][1];
		}
		if (f[fir][0] <= s[second][0]) {
			fir++;
		} else {
			second++;
		}
 	}
	if (fir != f.size()) {
		ll diff = abs(s[second - 1][0] - f[fir][0]);
		if (diff < minV) {
			ll prev = minV;
			ll prevIdx = minIdx;
			minV = diff;
			minIdx = s[fir][1];
			secondMinV = prev;
			secondMinIdx = prevIdx;
		} 
	}
	return vector<vector<ll>> {vector<ll>{minV, minIdx}, vector<ll>{secondMinV, secondMinIdx}};
}

ll solve(int N, vector<ll> &a, vector<char> &c) {
	vector<vector<ll>> rdogs, gdogs, bdogs;
	for (int i = 0; i < 2* N; i++) {
		if (c[i] == 'R') {
			rdogs.push_back( vector<ll> {a[i], i});
		} else if (c[i] == 'G') {
			gdogs.push_back( vector<ll> {a[i], i});
		} else {
			bdogs.push_back( vector<ll> {a[i], i});
		}
	}
	if (rdogs.size() % 2 == 0 && bdogs.size() % 2 == 0 && gdogs.size() % 2 == 0) {
		return 0;
	}

	if (gdogs.size() % 2 == 0) {
		auto tmp = gdogs;
		gdogs = rdogs;
		rdogs = tmp;
	}
	else if (bdogs.size() % 2 == 0) {
		auto tmp = bdogs;
		bdogs = rdogs;
		rdogs = tmp;
	}

	if (rdogs.size() % 2 == 0) {

		// cout << "rdogs size: " << rdogs.size() <<" bdogs size: " << bdogs.size() <<" gdogs size: " << gdogs.size() << endl;
		// first case 
		sort(gdogs.begin(), gdogs.end());
		sort(bdogs.begin(), bdogs.end());
		auto res0 = twoLessDiff(gdogs, bdogs);
		ll mn = res0[0][0];
		if (mn == 0) {
			return 0;
		}
		if (rdogs.size() == 0) {
			return mn;
		}

		// second case
		sort(rdogs.begin(), rdogs.end());
		auto res1 = twoLessDiff(rdogs, gdogs);
		auto res2 = twoLessDiff(rdogs, bdogs);
		// 2 answers: vector<ll> -> distance, rdogsIndx
		if (res1[0][1] == res2[0][1]) {
			mn = min(mn, min(res1[0][0] + res2[1][0], res1[1][0] + res2[0][0]));
		} else {
			mn = min(mn, res1[0][0] + res2[0][0]);
		}
		return mn;
	}
	return -1;
} 

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<ll> a(N);
	vector<char> c(N);
	for (int i = 0; i < 2 * N ; i++) {
		cin >> a[i] >> c[i];
	}
	ll res = solve(N, a, c);
	cout << res << endl;
}
/********  Main() Ends Here *************/