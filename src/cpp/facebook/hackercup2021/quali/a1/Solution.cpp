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
	string s;
	cin >> s;
	// iterate over 26 characters, calculate every possibilities
	int res = 1e8;
	int cur = 0;
	int n = s.size();
	set<char> vowels{'A', 'E', 'I', 'O', 'U'};
	
	for (int i = 0; i < 26; i++) {
		cur = 0;
		char target = 'A' + i;
		// cout << "target: " << target << endl;sz
		bool isVowel;
		if (vowels.find(target) != vowels.end()) {
			isVowel = true;
		} else {
			isVowel = false;
		}

		for (int k = 0; k < n; k++) {
			if (s[k] == target) {
				continue;
			}
			if (isVowel) {
				if ( vowels.find(s[k]) != vowels.end()) {
					cur += 2;
				} else {
					cur += 1;
				}
			} else {
				if ( vowels.find(s[k]) != vowels.end()) {
					cur += 1;
				} else {
					cur += 2;
				}
			}
		}
		res = min(cur, res);
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
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
}
/********  Main() Ends Here *************/