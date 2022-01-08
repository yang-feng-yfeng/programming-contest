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
#define rep(i,l,r) for(ll i=l;i<=r;i++)

queue<int> res_q; 
set<int> vis;


int backtracking(int n) {
	if (res_q.size () == n) {
		cout << "Yes\n";
		return 0;
	}
	rep (i, 0, n) {
		if (vis.find(i) == vis.end()) {
			vis.emplace(i);
		}

	}

}

int solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ab(n);
	vector<vector<int>> cd(n);
	rep(i, 0, m-1) { 
		int a, b; 
		cin >> a >> b; 
		a--;
		b--;
		ab[a].emplace_back(b);
		ab[b].emplace_back(a);
	}
	rep(i, 0, m-1) { 
		int c, d; 
		cin >> c >> d; 
		c--;
		d--;
		cd[c].emplace_back(d);
		cd[d].emplace_back(c);
	}

	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/