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
#include <unordered_set>

using namespace std;
using ll = long long;
vector<ll> primes;

// string toStr(vector<int> & cur) {
// 	string toRet= "";
// 	for (int i = 0; i < cur.size(); i++) {
// 		if (i != 0) {
// 			toRet += " "; 
// 		}
// 		toRet += cur[i];
// 	}
// 	return toRet;
// }

ll test(ll ng, vector<int> & priCount, vector<int> & cur, ll curProd, unordered_set<ll>& mem) {
	// string curStr = toStr(cur);
	// cout << "curStr: " << curStr << endl;
	if (mem.find(curProd) != mem.end()) {
		// cout << "mem: " << mem.size() << endl;
		// cout << "found: " << endl;
		return 0;
	} else {
		ll cnt = 0;
		mem.insert(curProd);
		ll k = curProd;
		// cout << " curK : " << k << endl;
		ll a2 = (ng / k + 1 - k);
		// cout << "ng: " << ng << endl;
		// cout << " 2a  : " << a2 << endl;
		if (a2 > 0 && a2 % 2 == 0) {
			cnt++;
			// cout << "cnt : " << cnt;
		}
		for (int i = 0; i < priCount.size(); i++) {
			if (priCount[i] != 0 && priCount[i] - cur[i] >= 1) {
				cur[i] ++;
				curProd *= primes[i];
				cnt += test(ng, priCount, cur, curProd, mem);
				cur[i] --;
				curProd /= primes[i];
			}
		}
		return cnt;
	}
}


ll solve(ll g) {
	ll ng = g * 2;
	int primeSize = primes.size();
	vector<int> priCount(primeSize, 0);
	for (int i = 0; ng > 1 && i < primeSize; i++) {
		while (ng % primes[i] == 0) {
			ng /= primes[i];
			// cout << "ng: " << ng << endl;
			priCount[i] ++;
		}
	}
	unordered_set<ll> mem;
	vector<int> cur(primeSize, 0) ;
	// cout << "test : " << endl;
	// ll cnt =  test(g * 2, priCount, cur , 1, mem);
	ll cnt = 1;
	for (int i = 1; i < primeSize; i++) {
		if (priCount[i] != 0) {
			cnt *= priCount[i] + 1;
		}
	}
	if (ng != 1) {
		cnt *= 2;
	}
	return cnt;
}

/********** Main()  function *******/
int main()
{
	for (int i = 2; i < 1e6+1; i++) {
		if (primes.empty()) {
			primes.push_back(i);
		} else {
			bool isPrime = true;
			int upper = (int)floor((float)sqrt(i));
			for (int j = 0; isPrime && j < primes.size() && primes[j] <= upper; j++) {
				int p = primes[j];
				if (i % p == 0) {
					isPrime = false;
				}
			}
			if (isPrime) {
				primes.push_back(i);
			}
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T ; i++) {
		ll G;
		cin >> G;
		ll res = solve(G);
		cout << "Case #" << (i+1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/