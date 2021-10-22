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
#include <unordered_set>

using namespace std;
using ll = long long;

void backtracking(	unordered_set<string> used, string picked, string rest, ll & res, string n) {
	if (used.find(picked) != used.end()) {
		return;
	} else {
		used.insert(picked);
	}
	string itr = rest;
 	for(char i : itr) {
		picked.push_back(i);

		rest.erase(rest.find(i), 1);
		sort(picked.rbegin(), picked.rend());
		sort(rest.rbegin(), rest.rend());

		// cout << "picked: " << picked << " rest " << rest << endl;
		res = max(res, stoll(picked) * stoll(rest));
		if (rest.size() > 1) {
			backtracking(used, picked, rest, res, n);
		}

		picked.erase(picked.find(i), 1);
		rest.push_back(i);
	}
}

int solve() {
	string n;
	cin >> n;
	string rest = n;
	string picked = "";
	ll res = 0;
	unordered_set<string> used;
	backtracking(used, picked, rest, res, n);
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	int res = solve();
	return 0;
}
/********  Main() Ends Here *************/