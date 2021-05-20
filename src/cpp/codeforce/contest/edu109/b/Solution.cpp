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

int solve(int n, vector<int> & a) {
	if (a[0] == n && a[n-1] == 1) {
		return 3;
	}
	if (a[0] == 1 || n == a[n-1]) {
		for (int i = 0; i < n; i++) {
			if (i+1 != a[i]) {
				return 1;
			}
		}
		return 0;
	}
	return 2;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		int N;
		cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N ; i++) {
			cin >> a[i];
		}
		int res = solve(N, a);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/