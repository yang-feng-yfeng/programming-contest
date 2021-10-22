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

/********** Main()  function *******/
int main()
{
	int n, q;
	string s;
	cin >> n >> q;
	cin >> s;
	vector<vector<int>> preCnt(n+1, vector<int>(26, 0));

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			preCnt[i][s[i-1] - 'a'] ++;
		} else {
			for (int j = 0; j < 26; j++) {
				preCnt[i][j] = preCnt[i-1][j];
			}
			preCnt[i][s[i-1] - 'a'] ++;
		}
	}

	for (int t = 0; t < q ; t++) {
		int l, r;
		cin >> l >> r;
		ll res = 0;
		for (int i = 0; i < 26; i++) {
			res += (preCnt[r][i] - preCnt[l-1][i]) * (i+1);
		}
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/