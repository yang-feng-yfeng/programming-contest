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
	int n,a, y, x;
	cin >> n >> a >> x >> y;
	int res = 0;
	if (n <= a ) {
		res = n * x;
	} else {
		res = a * x + (n - a) * y;
	}
	cout << res << endl;
}
/********  Main() Ends Here *************/