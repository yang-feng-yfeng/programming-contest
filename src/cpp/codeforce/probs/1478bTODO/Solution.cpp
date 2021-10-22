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
vector<int> l(1e9, 0);

bool seven(int num) {
	int rem = 0;
	while (num > 1 && rem != 7) {
		rem = num % 10;
		num = num / 10;
	}
	return num > 1;
}

bool lucky(int num) {
	if (l[num] == 1) {
		return true;
	} else if (l[num] == -1) {
		return false;
	} else {
		if (seven(num)) {
			l[num] = 1;
			return true;
		}
		int div = 7;
		while (div < num) {
			if (lucky((num - div))) {
				l[num] = 1;
				return true;
			}
			div *= 10;
		}
		l[num] = -1;
		return false;
	}
}

int solve() {
	int q, d;
	cin >> q >> d;
	vector<int> a(q);
	int ma = 0;
	for (int i = 0; i < q; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < q; i++) {
		if (lucky(a[i])) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		solve();
	}
	return 0;
}
/********  Main() Ends Here *************/