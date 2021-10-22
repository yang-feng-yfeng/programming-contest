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
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> a(m);

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int c;
			cin >> c;
			a[i].emplace_back(c);
		}
	}

	unordered_map<int, pair<int, int>> colorToCylinder;
	vector<pair<int, int> > events;
	int idx = 0;
	int cur = n;
	for (int i = 0; i < m; i++) {
		events.emplace_back(make_pair(i, 0));
	}

	while (cur > 0) {
		int nxt = -1;
		int nxtIdx = -1;
		if (idx < events.size()) {
			nxt = events[idx].first;
			nxtIdx = events[idx++].second;
		}
		else 
			break;
		if (colorToCylinder.find(a[nxt][nxtIdx]) == colorToCylinder.end()) {
			colorToCylinder[a[nxt][nxtIdx]] = make_pair(nxt, nxtIdx);
		} else {
			// find a pair
			cur --;
			int cyl = colorToCylinder[a[nxt][nxtIdx]].first;
			int cylidx = colorToCylinder[a[nxt][nxtIdx]].second;
			colorToCylinder.erase(a[nxt][nxtIdx]);
			if (nxtIdx + 1 < a[nxt].size())
				events.emplace_back(make_pair(nxt, nxtIdx+1));
			if (cylidx + 1 < a[cyl].size())
				events.emplace_back(make_pair(cyl, cylidx+1));
		}
	}
	if (cur > 0) 
		cout << "No" << endl;
	else {
		cout << "Yes" << endl;
	}
}
/********  Main() Ends Here *************/