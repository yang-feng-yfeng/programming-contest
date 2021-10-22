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
	int n;
	cin >> n;
	if (n % 2 == 0) {
		for (int i = 0; i < n; i+=2) {
			if (i == 0) {
				cout << (i + 2) << " " << (i + 1); 
			} else {
				cout << " " << ( i + 2) << " " << (i + 1);
			}
		}
	} else {
		int i = 0;
		for (; i < n-3; i+=2) {
			if (i == 0) {
				cout << (i + 2) << " " << (i + 1); 
			} else {
				cout << " " << ( i + 2) << " " << (i + 1);
			}
		}
		if ( i != 0 ) {
			cout << " ";
		}
		cout << (n) << " " << (n-2) << " " << (n-1) ; 
	}
	cout << endl;
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
}
/********  Main() Ends Here *************/