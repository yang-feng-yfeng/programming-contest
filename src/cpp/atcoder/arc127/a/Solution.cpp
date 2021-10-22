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
	string n;
	cin >> n;
	vector<ll> s(17);
	s[0] = 0;
	for (int i = 1; i <= 16; i++) {
		s[i] = s[i-1] + pow(10, i-1);
	}
	ll res = 0;
	ll num = stoll(n);
	int digit = n.size() - 1;

	for (char c : n) {
		int i = (int)(c - '0');
		if (i == 0) {
			break;
		}
		else if (i >= 1) {
			if (digit > 0) {
				res += num % (ll)(pow(10, digit)) + 1;
				res += s[digit] + s[digit - 1];
			} else {
				res += 1;
				break;
			}
			// cout << "res: " << res << endl;
		}
		// else if (i > 1) {
		// 	res += s[digit+1];
		// 	break;
		// }
		// cout << "digit " << digit << endl;
		num = num % ((ll) pow(10, digit));
		digit--;
	}
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/