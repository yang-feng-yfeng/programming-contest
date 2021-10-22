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
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int n ;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		// first case: a1, 1, a3, 1...
		// second case: 1, a2, 1, a4...
		ll firstSum = 0;
		ll secondSum = 0;
		vector<int> first(n, 1);
		vector<int> second(n, 1);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				firstSum += a[i];
				first[i] = a[i];
			} else {
				secondSum += a[i];
				second[i] = a[i];
			}
		}

		if (firstSum >= secondSum) {
			for (int i = 0 ; i < n; i++) {
				if ( i == 0) {
					cout << first[i];
					continue;
				}
				cout << " " << first[i] ;
			}
		} else {
			for (int i = 0 ; i < n; i++) {
				if ( i == 0) {
					cout << second[i];
					continue;
				}
				cout << " " << second[i] ;
			}
		}
		cout << endl;
	}
}
/********  Main() Ends Here *************/