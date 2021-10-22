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
	int n; cin >> n;
	vector<pair<int,int>> events;
	for (int i = 0; i < n; i++) {
		int f, s;
		cin >> f >> s;
		events.push_back(make_pair(f, 1));
		events.push_back(make_pair(f + s, -1));
	}
	sort(events.begin(), events.end());
	int cur = 0;
	int prev = -1;
	map<int, int> res;

	for (auto p : events) {
		int start = p.first;
		int type = p.second;
		// cout << "start: " << start << " type: " << type << endl;


		int dur = prev == -1 ? 0 : start - prev;
		res[cur] += dur;
		// cout << "cur: " << cur << endl;
		prev = start;
		if (type == 1) {
			cur ++;
		} else {
			cur --;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i != 1)  {
			cout << " ";
		}
		cout << res[i] ;
	}
	cout << endl;
	return 0;
}
/********  Main() Ends Here *************/