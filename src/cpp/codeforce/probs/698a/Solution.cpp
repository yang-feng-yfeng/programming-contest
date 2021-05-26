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
	vector<int> a(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	// vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt ++;
			continue;
		}
		if (i == 0) {
			continue;
		}
		if (a[i] == 1) {
			if (a[i-1] == 1) {
				a[i] = 0;
				cnt++;
			} 
		}
		if (a[i] == 2) {
			if (a[i-1] == 2) {
				a[i] = 0;
				cnt++;
			} 
		}
		if (a[i] == 3) {
			if (a[i-1] == 1) {
				a[i] = 2;
			}
			if (a[i-1] == 2) {
				a[i] = 1;
			}
		}
	}
	cout << cnt << endl;
}
/********  Main() Ends Here *************/