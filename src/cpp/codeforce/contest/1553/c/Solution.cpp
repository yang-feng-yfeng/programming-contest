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

int calc(string rel) {
	int diff = 0;
	int round = 0;
	while (round < 10) {
		if (rel[round] == '?')
			return 100;
		if (round % 2 == 0) {
			diff += rel[round] == '1' ? 1 : 0;
		} else {
			diff += rel[round] == '1' ? -1 : 0;
		}
		int last = (10 - round) / 2; 
		int win = last + ((round % 2 == 0) ? -1 : 1) * diff ;
		int lost = (9 - round) / 2 + ((round % 2 == 0) ? 1 : -1) * diff;
		// last *= (round % 2 == 0) ? -1 : 1;
		// cout << "round : " << round << " diff: " << diff << " lost: " << lost << " win: " << win << endl;
		if (lost < 0 || win< 0) {
			return round + 1;	
		} 
		round++;
	}
	return round;
}

int test(string pre, int cur, string rel) {
	int res = calc(rel);
	// cout << " rel: " << rel << " res: " << res << endl;
	if (res != 100) {
		return res;
	}
	while (cur < 10) {
		if (pre[cur] == '?') {
			rel[cur] = '1';
			int res1 = test(pre, cur+1, rel);
			rel[cur] = '0';
			int res2 = test(pre, cur+1, rel);
			return min(res1, res2);
		}
		cur++;
	}
	return calc(rel);
}

int solve() {
	string pre;
	cin >> pre;
	int cur = 0;
	string rel = pre;
	while (cur < 10) {
		if (pre[cur] == '?') {
			rel[cur] = '1';
			int res1 = test(pre, cur+1, rel);
			rel[cur] = '0';
			int res2 = test(pre, cur+1, rel);
			return min(res1, res2);
		}
		cur++;
	}
	return calc(rel);
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