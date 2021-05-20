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

int solve(int k) {

	int a = gcd(k, 100 - k);
	return 100 / a;

}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		int k;
		cin >> k;
		int res = solve(k);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/