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
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int t = 0; t < n ; t++) {
		int tmp;
		cin >> tmp;
		a[t] = make_pair(tmp, t+1);
	}
	sort(a.rbegin(), a.rend());
	cout << (a[1].second) << "\n";
	return 0;
}
/********  Main() Ends Here *************/