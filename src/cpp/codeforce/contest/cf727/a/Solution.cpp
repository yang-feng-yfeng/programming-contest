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

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		ll n, x, d;
		cin >> n >> x >> d;

		ll res = 0;
		ll cntInRange = d/x;
		if (n > cntInRange) {
			res += cntInRange * (n - cntInRange);
		}
		ll restCnt = min(n-1, cntInRange-1);
		res += restCnt * (restCnt + 1) / 2; 
		cout << res << endl;
	}

}
/********  Main() Ends Here *************/