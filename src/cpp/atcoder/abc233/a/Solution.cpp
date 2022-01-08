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
	int x, y;
	cin >> x >> y;
	if (x >= y) {
		cout << "0" << endl; 
	} else {
		int r = (y - x	);
		if ( r % 10 == 0) {
			cout << (r / 10) << endl;
		} else {
			cout << (r / 10 + 1) << endl;
		}
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
}
/********  Main() Ends Here *************/