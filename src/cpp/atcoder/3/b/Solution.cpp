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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll div = (c * d - b);
	ll k;
	if (div > 0) {
		k = ceil( (long double) 1.0 * a / div);
	} else {
		k = -1;
	}
	if (k >= 0) {
		cout << k << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/