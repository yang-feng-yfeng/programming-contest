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

void solve(int n, int m, vector<vector<int>> & a) {
	vector<vector<int>> events; 
	for (int i = 0; i < m; i++) {
		events.emplace_back(vector<int>{a[i][0], 1});
		events.emplace_back(vector<int>{a[i][1] + 1, -1});
	}
	sort(events.begin(), events.end());
	int v = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		while (cur < events.size() && i == events[cur][0]) {
			v += events[cur][1];
			cur ++;
		}
		if (v != 1) {
			cout << i << " " << v << endl;
			return;
		}
	}
	cout << "OK" << endl;
}

/********** Main()  function *******/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m , vector<int> (2));
	for (int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	solve(n, m, a);
	// cout << res[0] << " " << res[1] << endl;
}
/********  Main() Ends Here *************/