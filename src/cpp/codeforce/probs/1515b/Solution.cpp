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
		ll n;
		cin >> n;
		// case 1
		ll d = sqrt(n / 2);
		if (d * d * 2 == n ) {
			cout << "YES" << endl;
			continue;
		}
		ll d2 = sqrt(n / 4);
		if (d2 * d2 * 4 == n) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/