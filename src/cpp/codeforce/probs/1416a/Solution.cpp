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
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> f(n+1, 1);
		vector<int> prev(n + 1, -1);
		vector<int> res(n+1, -1);
		for (int i = 0; i < n; i++) {
			int v = a[i];
			int pr = prev[v];
			prev[v] = i;
			f[v] = max(f[v], i - pr);
		}

		for (int i = 0; i < n; i++) {
			if (prev[i] != -1) {
				f[i] = max(f[i], n - prev[i]);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (prev[i] != -1) {
				for (int j = f[i]; j <= n; j++) {
				if (res[j] == -1) {
					res[j] = i;
				} else {
					break;
				}
			}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				cout << res[i];
			} else {
				cout << " " << res[i];
			} 
		}
		cout << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/