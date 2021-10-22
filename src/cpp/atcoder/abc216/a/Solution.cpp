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
	double d;
	cin >> d;
	int xy  = (int) (d * 10);
	int x = xy / 10;
	int y = xy % 10;
	if (y <= 2) {
		cout << x << "-" << endl;
	} else if (y <= 6 && y >= 3) {
		cout << x << endl;
	} else {
		cout << x << "+" << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/