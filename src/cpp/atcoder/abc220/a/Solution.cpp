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
	int a, b, c;
	cin >> a >> b >>c;
	while (a <= b) {
		if (a % c == 0) {
			cout << a << endl;
			return 0;
 		}
		a++;
	}
	cout << "-1" << endl;
	return 0;
}
/********  Main() Ends Here *************/