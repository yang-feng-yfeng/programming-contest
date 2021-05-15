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

ll solve(ll n, ll m, ll x) {
	int nc = (x-1) / n;
	int nr = (x-1) % n;

	return nr * m + nc + 1;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		ll n, m, x;
		cin >> n >> m >> x;
		ll res = solve(n , m, x);
		cout <<  res << endl;
	}
}
/********  Main() Ends Here *************/