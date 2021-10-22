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
vector<int> primes;

ll cnt(int l, int r) {
	// cnt l with all rest numbers;
	if (find(primes.begin(), primes.end(), l) != primes.end()) {
		return 0;
	}
	else {
		ll res = 0;
		vector<int> primeFactor(primes.size());
		for (int i = 0; i < primes.size(); i++) {
			int prime = primes[i];
			if (prime > l ) {
				break;
			} else {
				primeFactor[i]++;
			}
		}
		for (int i =0; i< primes.size(); i++) {
			if (primeFactor[i] != 0) {
				res += (r - l) / primes[i];
			}
		}

	}
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
	int l, r;
	cin >> l >> r;
	ll res = 0;
	// imaging x always < y, so the final res = res * 2

	cout << endl;
}
/********  Main() Ends Here *************/