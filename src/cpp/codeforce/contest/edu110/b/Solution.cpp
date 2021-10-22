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

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		int n ;
		cin >> n;

		vector<int> odd;
		int nbEven = 0;
		int nbOdd = 0;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				nbEven ++;
			} else {
				odd.push_back(a);
				nbOdd++;
			}
		}

		int res = (n - 1 + n - nbEven ) * nbEven / 2;
		for (int i = 0; i < odd.size(); i++) {
			for (int j = i + 1; j < odd.size(); j++) {
				if (gcd(odd[i], odd[j]) > 1) {
					res++;
				}
			}
		}
		cout << res << endl;

	}
}
/********  Main() Ends Here *************/