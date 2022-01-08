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

int solve() {
	string s, t;
	cin >> s >> t;
	int dif = (t[0] - s[0]);
	dif = dif >= 0 ? dif : (dif + 26);
	bool ok = true;
	rep(i, 1, s.size() -1) {
		int cur = (t[i] - s[i]);
		cur = cur >= 0 ? cur : (cur + 26);
		if (dif != cur) {
			ok = false;
			break;
		}
	}
	cout << (ok ? "Yes" : "No") << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
	return 0;
}
/********  Main() Ends Here *************/