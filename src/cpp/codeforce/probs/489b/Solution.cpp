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

int solve(int n, int m, vector<int>& a, vector<int>& b) {
	int f = 0;
	int s = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int cnt = 0;
	while (f < n && s < m) {
		if (abs((ll) a[f] - b[s]) <= 1) {
			f++;
			s++;
			cnt++;
		} else if (a[f] < b[s]) {
			f++;
		} else {
			s++;
		}
	}
	return cnt;
}

/********** Main()  function *******/
int main()
{
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i =0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int res = solve(n, m, a, b);
	cout << res << endl;
}
/********  Main() Ends Here *************/