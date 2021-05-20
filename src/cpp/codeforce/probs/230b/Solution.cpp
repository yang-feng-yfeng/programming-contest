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
vector<ll> primes; 

bool solve(ll n) {
	if (n == 1) 
		return false;
	ll a = (ll) sqrt(n);
	if (a * a != n) {
		return false;
	}
	for (int i = 0 ; i < primes.size() && primes[i] <= sqrt(a); i++) {
		if (a % primes[i] == 0) {
			return false;
		} 
	}
	return true;
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;

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

	for (int i = 0; i < N ; i++) {
		ll a;
		cin >> a;
		bool res = solve(a);
		cout << (res ? "YES": "NO") << endl;
	}
}
/********  Main() Ends Here *************/