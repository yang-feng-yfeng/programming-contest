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
	string w;
	cin >> w;
	string tmp;
	// char c;
	for (int i = 0; i < n; i++) {
		if (w[i] == 'F') {
			continue;
		} else {
			if (tmp.size() == 0) {
				tmp += w[i];
			} else {
				 if (w[i] != tmp[tmp.size()- 1]) {
					 tmp += w[i];
				 } 
			}
		}
	}
	return max(0, (int)tmp.size() - 1);
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int res = solve();
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/