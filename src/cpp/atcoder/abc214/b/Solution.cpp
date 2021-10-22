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
	int s, t;
	cin >> s >> t;
	int res = 0;
	for (int a = 0; a <= s; a++) {
		for (int b = 0; b <= s; b++) {
			for (int c = 0; c <= (s - a - b); c++) {
				if (a * b * c <= t) {
					res ++;
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}
/********  Main() Ends Here *************/