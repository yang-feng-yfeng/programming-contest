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

void solve(int n, int m, vector<vector<int>>& x) {
	vector<int> res (n, -1);
	vector<vector<int>> cp(n, vector<int>(4));
	vector<vector<int>> even;
	vector<vector<int>> odd;
	for (int i = 0; i < n; i++) {
		cp[i][0] = x[i][0];
		cp[i][1] = x[i][1];
		cp[i][2] = -1;
		cp[i][3] = i;
	}
	sort(cp.begin(), cp.end());

	for (int i = 0; i < n; i++) {
		if (cp[i][0] % 2 == 0) {
			even.push_back(cp[i]);
			// cout << "even index" << cp[i][3] << endl;
		} else {
			odd.push_back(cp[i]);
			// cout << "odd index" << cp[i][3] << endl;
		}
	}

	// cout << "even size: " << even.size() <<endl;
	// cout << "odd size: " << odd.size() <<endl;
	// even
	stack<vector<int>> right;
	queue<vector<int>> left;
	for (int i = 0; i < even.size(); i++) {
		auto cur = even[i];
		if (cur[1] == 1) {
			right.push(cur);
		} else {
			if (right.empty()) {
				left.push(cur);
			} else {
				vector<int> p = right.top();
				right.pop();
				int diff = cur[0] - p[0];
				res[p[3]] = diff / 2;
				res[cur[3]] = diff / 2;
			}
		}
	}
	// right part, right part can left 0 or 1 bot
	// cout << "begin right part" <<endl;
	while (right.size() > 1) {
		auto last = right.top();
		right.pop();
		auto sec_last = right.top();
		right.pop();
		int distance = (m-last[0]) + (m-sec_last[0]);
		res[last[3]] = distance / 2;
		res[sec_last[3]] = distance / 2;
	}

	// cout << "begin left part" <<endl;
	while (left.size() > 1) {
		auto first = left.front();
		left.pop();
		auto second = left.front();
		left.pop();
		int distance = first[0] + second[0];
		res[first[3]] = distance / 2;
		res[second[3]] = distance / 2;
	}
	
	if (right.size() == 1 && left.size() == 1) {
		auto first = left.front();
		left.pop();
		auto last = right.top();
		right.pop();
		int distance = m + (m - last[0]) + first[0];
		res[first[3]] = distance / 2;
		res[last[3]] = distance / 2;
	}

	while (!right.empty()) right.pop();
	while (!left.empty()) left.pop();

	// odd

	// cout << "begin odd part " << endl;
	for (int i = 0; i < odd.size(); i++) {
		vector<int> cur = odd[i];
		if (cur[1] == 1) {
			right.push(cur);
			// cout << "right push  " << cur[0] << endl;
		} else {
			if (right.empty()) {
				left.push(cur);
			} else {
				vector<int> p = right.top();
				right.pop();
				// cout << "right pop  " << p[0] << endl;
				int diff = cur[0] - p[0];
				res[p[3]] = diff / 2;
				res[cur[3]] = diff / 2;
			}
		}
	}
	// right part, right part can left 0 or 1 bot
	// cout << "begin right odd part" << endl;
	// cout << "right size: " << right.size() << endl;
	while (right.size() > 1) {
		auto last = right.top();
		right.pop();
		auto sec_last = right.top();
		right.pop();
		int distance = (m-last[0]) + (m-sec_last[0]);
		// cout << "last[0] : " << last[0] << endl;
		// cout << "sec_last[0] : " << sec_last[0] << endl;
		res[last[3]] = distance / 2;
		res[sec_last[3]] = distance / 2;
	}

	// cout << "begin left odd part" << endl;
	while (left.size() > 1) {
		auto first = left.front();
		left.pop();
		auto second = left.front();
		left.pop();
		int distance = first[0] + second[0];
		res[first[3]] = distance / 2;
		res[second[3]] = distance / 2;
	}
	
	if (right.size() == 1 && left.size() == 1) {
		auto first = left.front();
		left.pop();
		auto last = right.top();
		right.pop();
		int distance = m + (m - last[0]) + first[0];
		res[first[3]] = distance / 2;
		res[last[3]] = distance / 2;
	}

	// cout << "print result" << endl;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << res[i];
	}
	cout << endl;
}

/********** Main()  function *******/
int main()
{
	int T, N, M;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> N >> M;
		vector<vector<int>> x(N, vector<int>(2));
		for (int i = 0; i< N; i++) {
			cin >> x[i][0];
		}
		char dir = ' ';
		for (int i = 0; i< N; i++) {
			cin >> dir;
			if (dir == 'L') {
				x[i][1] = -1;
			} else {
				x[i][1] = 1;
			}
		}
		// cout << "begin solving" <<endl;
		solve(N, M, x);
	}
}
/********  Main() Ends Here *************/