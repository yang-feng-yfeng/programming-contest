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

bool isSorted(vector<int> & a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != i + 1) {
			return false;
		}
	}
	return true;
}

int solve() {
	int n;
	cin >> n;
	vector<int> a(n); 
	for (int i = 0; i < n; i++) cin >> a[i];

	int op = 0;
	ll res = 0;
	ll cur = 1;
	while (op != 0 || !isSorted(a)) {
		op = 0;
		if (cur % 2 == 1) {
			for (int i = 0; i < n - 2; i+=2) {
				if (a[i] > a[i+1]) {
					int tmp = a[i];
					a[i] = a[i+1];
					a[i+1] = tmp;
					op++;
				}
			}
		} else {
			for (int i = 1; i < n -1; i+=2) {
				if (a[i] > a[i+1]) {
					int tmp = a[i];
					a[i] = a[i+1];
					a[i+1] = tmp;
					op++;
				}
			}
		} 
		if (op == 0 && isSorted(a)) {
			break;
		}
		cur++;
		res++;
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/