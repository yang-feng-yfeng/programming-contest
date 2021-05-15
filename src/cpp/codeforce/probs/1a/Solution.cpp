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


ll solve(ll n, ll m, ll a) {
	return (ll)(ceil((long double)n / a)) * ((ll) ceil((long double)m * 1.0 / a));
}

/********** Main()  function *******/
int main()
{
	int T;
	// cin >> T;
	// for (int t = 1; t<=T; ++t ) {
		ll n, m, a;
		cin >> n >> m >> a;
		ll res = solve(n, m, a);
		cout << res << endl;
	// }
}
/********  Main() Ends Here *************/