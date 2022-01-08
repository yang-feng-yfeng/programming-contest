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
	int l, r;
	string s;
	cin >> l >> r >> s;
	reverse(s.begin() + l - 1, s.begin() + r);
	cout << s << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	solve();
}
/********  Main() Ends Here *************/