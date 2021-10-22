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
vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		vector<int> color(n, 0);
		map<int, int> colorIdx;
		int idx = 1;
		for (int i = 0 ; i < n; i++) {
			for (int p: primes) {
				if (a[i] % p == 0) {
					if (colorIdx.find(p) == colorIdx.end()) {
						colorIdx[p] = idx++;
					}
					color[i] = colorIdx[p];
					break;
				}
			}
		}
		cout << (idx - 1) << endl;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << " ";
			}
			cout << color[i];
		}
		cout << endl;
	}
	
}
/********  Main() Ends Here *************/