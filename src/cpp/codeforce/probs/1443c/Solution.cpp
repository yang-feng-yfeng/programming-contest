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



int bs(vector<int>& a, vector<int>& b, int left, int right, int n) {
	if (left == right) {
		return left;
	}
	int mid = left + (right - left) / 2;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) {
			sum += b[i];
		} 
	}
	if (mid >= sum) {
		return bs(a, b, left, mid, n);
	} else {
		return bs(a, b, mid + 1, right, n);
	}
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int n ;
		cin >> n;
		vector<int> a(n), b(n);
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		for (int i =0 ; i < n; i++) {
			cin >> b[i];
		}
		
		int left = 1;
		int right = mx;
		int res = bs(a, b, left, right, n);
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/