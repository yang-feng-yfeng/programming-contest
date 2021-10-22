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

// ll countBeat(string s, int left, int right) {
// 	// start with * 
// 	ll n = right - left;
// 	int i = left;
	
// 	while (i < right && s[i] == '?') {
// 		i ++;
// 	}
// 	if (i == right || i == (right - 1)) {
// 		return n * (n+1) / 2;
// 	}

// 	// first non ? found. 
// 	ll res = 0;
// 	// vector<vector<int>>
// 	for (i = i + 1; i < right; i++) {
// 		if ((s[i-1] == '0' && s[i] == '1' ) || (s[i-1] == '1' && s[i] == '0')) {
// 			continue;
// 		} else {
// 			if (s[i] == '1' || s[i] == '0') {
// 				ll nbAdd = i - left;
// 				res += nbAdd * (nbAdd + 1) / 2;
// 				res += countBeat(s, i, right);
// 				return res;
// 			} else {
// 				// s[i] == ?
// 				int l = i - 1;
// 				int cntQ = 0;
// 				while ( i < right && s[i] == '?') {
// 					cntQ ++;
// 					i++;
// 				} 
// 				if (i == right) {
// 					return n * (n+1) / 2;
// 				}
// 				if (cntQ % 2 == 0) {
// 					if (s[l] == s[i]) {
// 						// break into 2 
// 						ll nbAdd = i - left;
// 						res += nbAdd * (nbAdd + 1) / 2;
// 						res += countBeat(s, l+1, right);
// 						int nbRev = i - (l + 1);
// 						res -= nbRev * (nbRev + 1) / 2;
// 						return res;
// 					} else {
// 						continue;
// 					}
// 				} else {
// 					if (s[l] == s[i]) {
// 						continue;
// 					} else {
// 						ll nbAdd = i - left;
// 						res += nbAdd * (nbAdd + 1) / 2;
// 						// cout << "left: " << left << " i: " << i << "res : " << res << endl;
// 						res += countBeat(s, l+1, right);
// 						// cout << "left: " << (l+1) << " right: " << right << "res : " << res << endl;
// 						int nbRev = i - (l + 1);
// 						res -= nbRev * (nbRev + 1) / 2;
// 						return res;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return n * (n+1) / 2;
// }

ll count(int l) {
	return (ll) l * (l + 1) / 2;
}

vector<ll> beauty(string s, int start) {
	// return vector < result, lastIdx
	// find first non ?
	int f = start;
	int n = s.size();
	while (f < n && s[f] == '?' ) {
		f++; 
	}

	if (f == n) {
		return vector<ll> {count(f - start), n} ;
	}

	if (s[f] == '1') {
		int mod = f % 2;
		f++;
		while (f < n) {
			if (s[f] == '?') {
				f++;
			} else if (f % 2 == mod && s[f] == '1') {
				f++;
			} else if (f % 2 != mod && s[f] == '0') {
				f++;
			} else {
				return vector<ll> {count(f- start), f};
			}
		}
		if (f == n) {
			return vector<ll> {count(f - start), n} ;
		}
	} else {
		int mod = f % 2;
		f++;
		while (f < n) {
			if (s[f] == '?') {
				f++;
			} else if (f % 2 == mod && s[f] == '0') {
				f++;
			} else if (f % 2 != mod && s[f] == '1') {
				f++;
			} else {
				return vector<ll> {count(f- start), f };
			}
		}
		if (f == n) {
			return vector<ll> {count(f - start), n} ;
		}
	}
	return vector<ll> {-1, -1};
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		string s ;
		cin >> s;
		int start = 0;
		ll res = 0;
		while (start < s.size()) {
			auto v = beauty(s, start);
			res += v[0];
			start = v[1];
			if (start == s.size()) {
				break;
			}
			// cout << "start :  " << start << endl;
			int idx = start - 1;
			while (idx >= 0 && s[idx] == '?') {
				idx--;
			}
			res -= count(start - 1 -idx);
			start = idx + 1;
		}
		cout << res << endl;
	
	}
}
/********  Main() Ends Here *************/