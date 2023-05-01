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
#define rep(i,l,r) for(ll i=l;i<=r;i++)

// int solve() {
// 	int n;
// 	cin >> n;
// 	vector<ll> a(n);
// 	rep(i, 0, n-1) {
// 		cin >> a[i];
// 	}
// 	vector<pair<ll, ll>> subopt(n-1);
// 	rep(i, 0, n-2) {
// 		if (i == 0) {
// 			subopt[i] = make_pair(a[i] + a[i+1], -a[i] - a[i+1]);
// 		} else {
// 			subopt[i] = make_pair(
// 				max(subopt[i-1].first + a[i+1], subopt[i-1].second + a[i+1] ), 
// 				max(subopt[i-1].first - a[i]*((ll)2) - a[i+1], subopt[i-1].second + a[i]*((ll)2) - a[i+1]));
// 		}
// 	}
// 	return max(subopt[n-2].first, subopt[n-2].second);
// }

// /********** Main()  function *******/
// int main()
// {
// 	int T;
// 	cin >> T;
// 	for (int t = 0; t < T ; t++) {
// 		int res = solve();
// 		cout << res << endl;
// 	}
// }
// /********  Main() Ends Here *************/


/**
 * We can notice that by performing any number of operations, 
 * the parity of the count of negative numbers won't ever change. 
 * Thus, if the number of negative numbers is initially even, 
 * we can make it equal to 0 by performing some operations. 
 * So, for an even count of negative numbers, the answer is 
 * the sum of the absolute values of all numbers (since we can make all of them positive). 
 * And if the count of negative numbers is odd, we must have one negative number at the end. 
 * We will choose the one smallest by absolute value and keep the rest positive (for simplicity, we consider −0 as a negative number).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        long long sum = 0;
        int negs = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] < 0) {
                ++negs;
                a[i] = -a[i];
            }
            sum += a[i];
        }
        sort(a.begin(), a.end());
        if(negs & 1) sum -= 2 * a[0];
        cout << sum << "\n";
    }
}