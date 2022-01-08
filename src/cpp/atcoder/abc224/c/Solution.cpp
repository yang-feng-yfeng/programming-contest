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
#include <unordered_set>

using namespace std;
using ll = long long;

int solve() {
	int n;
	cin >> n;
	int res = n * (n - 1) * (n-2) / 6;
	vector<int> x(n);
	vector<int> y(n);

	for (int i =0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		unordered_map<double, int> kmap;
		for (int j = i + 1; j < n; j++) {
			double lk = (double) (1.0 * (y[j] - y[i]) / (x[j] - x[i]));
			lk = (lk > 0 ) ? lk : -lk;
			kmap[lk] ++;
		}
		for (auto pa : kmap) {
			if (pa.second > 1) {
				res -= (pa.second * (pa.second - 1)) / 2;
				cout << "pa.first: " << pa.first << " res : " << res << endl;
			}
		}
	}
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	int res = 0;

	for (int i =0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1 ; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				double k1 = (double) (1.0 * (y[j] - y[i]) / (x[j] - x[i]));
				double k2 = (double) (1.0 * (y[k] - y[i]) / (x[k] - x[i]));
				double k3 = (double) (1.0 * (y[k] - y[j]) / (x[k] - x[j]));
				k1 = (k1 > 0) ? k1 : -k1;
				k2 = (k2 > 0) ? k2 : -k2;
				k3 = (k3 > 0) ? k3 : -k3;

				if (k1 != k2 && k1 != k3 && k2 != k3) {
					res ++;
				}

			}
		}
	}
	cout << res << endl;
	return 0;
}
/********  Main() Ends Here *************/