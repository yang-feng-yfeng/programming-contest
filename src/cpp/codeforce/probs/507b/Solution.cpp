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
	ll r, x, y, xp, yp;
	cin >> r >> x >> y >> xp >> yp;
	long double dis = sqrt((long long)(xp - x) * (xp - x) + (yp - y) * (yp - y));
	// cout << "dis: " << dis << endl;
	long res = ceil(dis / 2 / r);
	cout << res << endl;
}
/********  Main() Ends Here *************/