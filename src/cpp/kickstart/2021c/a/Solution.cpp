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
ll mod = 1e9 + 7;

int testAll(int k, int nbDigit, string s, string curStr, int curDigit, bool isEven) {
	int cnt = 0;
	if (curDigit == nbDigit) {
		if (isEven) {
			string curPalin = curStr;
			string revStr = curStr;
			reverse(revStr.begin(), revStr.end());
			curPalin += revStr;
			if (curPalin < s) {
				cnt++;
			}
		} else {
			string curPalin = curStr;
			string revStr = curStr;
			reverse(revStr.begin(), revStr.end());
			for (int i = 0; i < k; i++) {
				if ((curPalin + (char)('a' + i) + revStr) < s) {
					cnt++;
				}
			}
		}
	} else {
		for (int i = 0; i < k; i++) {
			cnt += testAll(k, nbDigit, s, curStr + (char)('a'+i), curDigit + 1, isEven);
		}
	}
	return cnt;
}

int solve1(int n, int k, string s) {
	int cnt = 0;
	int nbDigit = n / 2;
	return testAll(k, nbDigit, s, "", 0, n % 2 == 0);
}

int solve(int n, int k, string s) {
	// split the string in 2 part, first part and second part, 
	// if first part smaller that second part, all palin
	// otherwise 
	int nbHalf = n/2;
	string first = s.substr(0, nbHalf);
	string last = s.substr(n - nbHalf, nbHalf);
	reverse(first.begin(), first.end());
	ll cnt = 1;
	bool timesK = false;
	if (first < last) {
		if (n % 2 == 0) {
			for (int i = 0; i < nbHalf; i++) {
				if (!timesK && k < (s[i] - 'a' + 1)) {
					// all rest 
					timesK = true;
				}
				cnt = ((cnt - 1) * k % mod + (timesK ? k: (s[i] - 'a' + 1))) % mod;
			}
		} else {
			for (int i = 0; i < nbHalf; i++) {
				if (!timesK && k < (s[i] - 'a' + 1)) {
					// all rest 
					timesK = true;
				}
				cnt = ((cnt - 1) * k % mod + (timesK ? k: (s[i] - 'a' + 1))) % mod;
			}
			cnt = ((cnt - 1) * k % mod + (timesK ? k : min(k, s[nbHalf] - 'a' + 1))) % mod;
		}
	} else {
		if (n % 2 == 0) {
			for (int i = 0; i < nbHalf - 1; i++) {
				if (!timesK && k < (s[i] - 'a' + 1)) {
					// all rest 
					timesK = true;
				}
				cnt = ((cnt - 1) * k % mod + (timesK ? k : min(k, (s[i] - 'a' + 1)))) % mod;
			}
			cnt = ((cnt - 1) * k  % mod +  (timesK ? k : min (k, s[nbHalf - 1] - 'a'))) % mod;
		} else {
			for (int i = 0; i < nbHalf; i++) {
				if (!timesK && k < (s[i] - 'a' + 1)) {
					// all rest 
					timesK = true;
				}
				cnt = ((cnt - 1) * k % mod + (timesK ? k : min(k, (s[i] - 'a' + 1)))) % mod;
			}
			cnt = ((cnt - 1) * k % mod + (timesK ? k : min(k, s[nbHalf] - 'a'))) % mod;
		}
	}
	return cnt;
}


/********** Main()  function *******/
int main()
{
	int T, N, K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		string a;
		cin >> a;
		int res = solve(N, K, a);
		int res1 = solve1(N, K, a); 
		cout << "Case #" << (i+1) << ": " << res  << " correct: " << res1 << endl;
		// cout << "Case #" << (i+1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/