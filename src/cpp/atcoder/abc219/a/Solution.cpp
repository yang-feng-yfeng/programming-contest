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
	int x;
	cin >> x;
	if (x >= 90) {
		cout << "expert" << endl;
		return 0;
	}
	if (x >= 70) {
		cout << (90 - x) << endl;
	} else if (x >= 40) {
		cout << (70 - x) << endl;
	} else {
		cout << (40 - x) << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/