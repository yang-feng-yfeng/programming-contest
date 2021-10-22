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

bool isInter(vector<ll> & f, vector<ll> & s) {
	if (s[2] != 1 && s[1] == s[0]) {
		return false;
	}
	if (f[2] != 1 && f[1] == f[0]) {
		return false;
	}
	if ((s[2] == 1 || s[2] == 2) && (f[2] == 1 || f[2] == 3)) {
		if (f[1] >= s[0]) {
			return true;
		}
	} else {
		if (f[1] > s[0]) {
			return true;
		}
	}
	// cout << "f: " << f[2] << " " << f[0] << " " << f[1] << endl;
	// cout << "s: " << s[2] << " " << s[0] << " " << s[1] << endl;
	return false;
}


ll solve(int N, vector<vector<ll>> & inter) {
	ll res = 0;
	sort(inter.begin(), inter.end());
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
		
			if (isInter(inter[i], inter[j])) {
				res++;
			} else {
				break;
			}
		
		}
	}
	cout << res << endl;
	return 0;
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<vector<ll>> inter(N, vector<ll>(3));
	for (int i = 0; i < N; i++) {
		cin >> inter[i][2] >> inter[i][0] >> inter[i][1];  
	}
	ll res = solve(N, inter);
	return 0;
}
/********  Main() Ends Here *************/