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
	int n;
	string s;
	cin >> n;
	cin >> s;
	string res = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			res = (i % 2 == 0) ? "Takahashi" : "Aoki";
			break;
		}
	}
	cout << res << "\n";
}
/********  Main() Ends Here *************/