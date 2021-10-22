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


bool isGood(vector<int> &vec, int i, int j) {
	for (int a = i; a <= j; a++) {
		for (int b = a + 1; b <= j; b++) {
			for (int c = b + 1; c <= j; c++) {
				if (vec[a] <= vec[b] && vec[b] <= vec[c]) {
					return false;
				} 
				if (vec[a] >= vec[b] && vec[b] >= vec[c]) {
					return false;
				}
			}
		}
	}
	return true;
}

int solve() {
	int n ;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int res = 0;
	int i = 0, j = 0;
	while ( i < n) {
		while (j < n && isGood(a, i, j)) {
			j++;
		}
		// cout << "i: " << i << " j: "  << j << endl;
		res += j - i;
		i++;
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