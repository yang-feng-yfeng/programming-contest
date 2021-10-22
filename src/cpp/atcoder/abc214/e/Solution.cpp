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
	vector<pair<int, int>> lr(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		lr[i] = make_pair(l, r);
	}
	// sort(lr.begin(), lr.end());
	vector<pair<int, int>> events;
	for (int i = 0; i < n; i++) {
		events.emplace_back(make_pair(lr[i].first - 1, 1));
		events.emplace_back(make_pair(lr[i].second - 1, -1));
	}
	sort(events.begin(), events.end());

	vector<pair<int, int>> mergedE;
	for (int i = 0; i < events.size() - 1; i++) {
		int j = i + 1;
		int cnt = events[i].second;
		while (j < events.size() && events[j].first == events[i].first && events[i].second == events[j].second) {
			cnt += events[j].second;
			j++;
		}
		mergedE.emplace_back(make_pair(events[i].first, cnt));
		i = j - 1;
	}


	int firstAva = 0;
	int curCnt = 0;

	for (auto e: mergedE) {
		int idx = e.first;
		int eventCnt = e.second;
		cout << "idx: " << idx <<  " eventCnt: " << eventCnt << "\n";

		if (eventCnt > 0) {
			if (curCnt == 0) {
				curCnt+= eventCnt;
				firstAva = idx;
			} else {
				int avSpots = idx - firstAva;
				cout << "idx: " << idx  << " avSpots: "  << avSpots << endl;
				curCnt = max(0, curCnt - avSpots);
				curCnt+= eventCnt;
				firstAva = idx;
			}
		} else {
			int avSpots = idx - firstAva + 1;
			cout << "idx: " << idx  << " avSpots: "  << avSpots << " curCnt: " << curCnt << endl;
			if (avSpots >= curCnt) {
				firstAva+= curCnt;
				cout << "idx: " << idx  << " firstAva: " << firstAva << endl;
				curCnt-= curCnt;
			} else {
				cout << "No" << "\n";
				return -1;
			}
		}
	}
	cout << "Yes" << "\n";
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
	return 0;
}
/********  Main() Ends Here *************/