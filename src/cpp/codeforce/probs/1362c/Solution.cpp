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
	int t;
	cin >> t;
	for (int k = 0;  k < t; k++) {
		ll n;
		cin >> n;
		ll res = n;
		ll div = 2;
		while (div <= n) {
			res += n / div;
			div *= 2;
		}
		cout << res << endl;
	}
	
}
/********  Main() Ends Here *************/