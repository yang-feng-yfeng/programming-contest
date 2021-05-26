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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n ; i++) {
		cin >> b[i];
	}

	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		r[i] = a[i] - b[i];
	}

	ll cnt = 0;
	int first = 0;
	int last = n-1;

	sort(r.begin(), r.end());
	while (first < last) {
		if (r[first] + r[last] > 0) {
			cnt += (last - first);
			last--;
		} else {
			first++;
		}
	}
	cout << cnt << endl;
}
/********  Main() Ends Here *************/