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
	int n; cin >> n;
	string enemy, ours;
	cin >> enemy >> ours;
	int res = 0;
	for (int i = 0 ; i < n; i++) {
		if (ours[i] == '1') {
			if (enemy[i] == '0') {
				res++;
			} else {
				if (i > 0 && enemy[i - 1] == '1') {
					res++;
					enemy[i-1] = '2';
				} else if (i < n - 1 && enemy[i+1] == '1') {
					res++;
					enemy[i+1] = '2';
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		// cout << res << endl;
	}
}
/********  Main() Ends Here *************/