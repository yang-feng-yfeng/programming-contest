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
    ll n, c;
    cin >> n >> c;
    vector<int> a(n);
    int res = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];    
    }
    int k = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] > c) {
            // cout << "k: "<< k << endl;
            break;
        } 
        k = i+1;
    }
    res += (n - k);
    for (int i = 0; i < k; i++) {
        a[i] = (int) log2 ( ((long double) c) / a[i] );
        // cout << "a :" << a[i] << endl;
    }

    int incre = 0;
    for (int i = k-1; i >= 0 ; i--) {
        if (a[i] - incre < 0) {
            res ++;
        } else {
            incre++;
        }
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