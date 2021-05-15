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

int solve(int n, vector<int>& s) {
	vector<int> count(5);
	int res = 0;
	for (int i = 0; i < n; i++) {
		count[s[i]] ++;
	}
	res += count[4];
	int onethree = min(count[1], count[3]);
	res += onethree;
	count[1] -= onethree;
	count[3] -= onethree;
	res += count[3];
	int twotwo = count[2] / 2;
	res += twotwo;
	count[2] -= 2 * twotwo;
	if (count[2] > 0) {
		res += 1;
		count[1] -= 2;
	}
	if (count[1] > 0) {
		res += ceil((float) 1.0 * count[1] / 4);
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	// int T, N;
	// cin >> T;
	// for (int t = 1; t<=T; ++t ) {
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n ; i++ ) {
		cin >> s[i];
	}
	int count = solve(n, s);
	cout << count << endl;
	// }
}
/********  Main() Ends Here *************/