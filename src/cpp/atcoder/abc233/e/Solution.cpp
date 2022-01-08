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
	string s;
	cin >> s;
	string reversed_res = "";
	int n = s.size();
	ll sum = 0;
	auto sc = s.c_str();
	for (int i = 0; i < n; i++) {
		sum += sc[i] - '0';
	}
	// cout << "reversed_res 1: " << reversed_res << endl;
	// cout << "sum: " << sum << endl;

	ll curSum = sum;
	ll overdu = 0;
	for (int i = 0; i < n; i++) {
		int curIdx = n - 1 - i;
		curSum = curSum + overdu;
		// cout << "curSum***: " << curSum << endl;

		reversed_res += to_string(curSum % 10);
		// cout << "reversed_res: " << reversed_res << endl;

		overdu = curSum / 10;
		sum -= (sc[curIdx] - '0');
		curSum = sum;
		// cout << "overdu: " << overdu << endl;
		// cout << "curSum: " << curSum << endl;

	}
	// cout << "reversed_res 2: " << reversed_res << endl;

	while (overdu > 0) {
		reversed_res += to_string((overdu % 10));
		overdu = overdu / 10;
		// cout << "overdu: " << overdu << endl;
	}
	// cout << "reversed_res 3: " << reversed_res << endl;

	reverse(reversed_res.begin(), reversed_res.end());
	cout << reversed_res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
}
/********  Main() Ends Here *************/