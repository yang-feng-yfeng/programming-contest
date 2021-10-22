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
	ll n;
	cin >> n;
	string res = "";
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
			res += "B";
		} else {
			n -= 1;
			res += "A";
		}
	}
	reverse(res.begin(), res.end());
	cout << res << "\n";
	return 0;
}
/********  Main() Ends Here *************/