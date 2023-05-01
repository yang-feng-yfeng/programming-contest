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

vector<ll> primes; 

pair<ll, ll> solveSub(ll n, map<ll, ll> & primesCount) {
	ll comMin = 1e6;
	ll res = 1;
	for (auto pc: primesCount) {
		comMin = min(pc.second, comMin);
	}
	for (auto it = primesCount.cbegin(); it != primesCount.cend();) {
		primesCount[it->first] -= comMin;
		res *= it->first;
		if (it -> second == 0) {
			primesCount.erase(it++);
		} else {
			++it;
		}
	}

	return make_pair(res, comMin);
}

ll solve() {
	map<ll, ll> primesCount;

	ll n;
	cin >> n;
	ll cpn = n;

	for (int i = 0; i < primes.size(); i++) {
		while (n % primes[i] == 0 && n > 1) {
			n /= primes[i];
			if (primesCount.find(primes[i]) != primesCount.end()) {
				auto count = primesCount[primes[i]];
				primesCount[primes[i]] = count + 1;
			} else {
				primesCount.emplace(primes[i], 1);
			}
		}
	}
	if (n > 1) {
		primesCount.emplace(n, 1);
	}

	n = cpn;
	ll res = 0;
	while(n > 1) {
		auto tempRes = solveSub(n, primesCount);
		n /= pow(tempRes.first, tempRes.second);
		res += tempRes.first * tempRes.second;
		// cout << "res temp: "<< res << " n: " << n << endl;
	}
	return res;

}

/********** Main()  function *******/
int main()
{
	for (int i = 2; i < 1e5+1; i++) {
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
	for (int t = 0; t < T ; t++) {
		ll res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/