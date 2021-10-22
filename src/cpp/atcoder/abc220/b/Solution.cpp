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

ll conv(ll a, ll k) {
	ll cur = 1;
	ll res = 0;
	while (a > 0) {
		int rm = a % 10;
		res += rm * cur;
		a /= 10;
		cur *= k;
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	ll k, a, b;
	cin >> k >> a >> b;
	ll res = conv(a, k) * conv(b, k);
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/