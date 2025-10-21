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
#define rep(i, l, r) for (ll i = l; i <= r; i++)

ll solve() {
	int n, m;
	ll d;
	cin >> n >> m >> d;
	vector<ll> a(n);
	vector<ll> b(m);
	rep (i, 0, n-1) {
		cin >> a[i];
	} 
	rep (j, 0, m-1) {
		cin >> b[j];
	}
	sort(a.begin(), a.end(), std::greater<ll>());
	sort(b.begin(), b.end(), std::greater<ll>());
	
	int i=0, j=0;
	while (i < n && j < m) {
		if (abs(a[i] - b[j]) <= d) {
			return a[i] + b[j];
		} else {
			if (a[i] < b[j]) {
				j++;
			} else {
				i++;
			}
			
		}
	}
	return -1;
}

/********** Main()  function *******/
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cout << solve() << endl;
}
/********  Main() Ends Here *************/