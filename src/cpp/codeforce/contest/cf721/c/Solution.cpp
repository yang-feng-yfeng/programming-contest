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

void solve(int n, vector<int>& a) {
	unordered_map<int, int> valueMap;
	int idx = 0;

	vector<vector<int>> preCount(n+1); 
	for (int i = 0; i < n ; i ++) {
		int curValue = a[i];

		if (valueMap.find(curValue) == valueMap.end()) {
			valueMap[curValue] = idx;
			idx++;
		}
		int curIdx = valueMap[curValue];
		// cout << "curIdx " << curIdx << endl;
		preCount[i+1].resize(curIdx + 1);
		if (i == 0) {
			preCount[i+1][curIdx]++;
		} else {
			for (int j = 0 ; j < preCount[i].size(); j++) {
				preCount[i+1][j] = preCount[i][j];
			}
			preCount[i+1][curIdx]++;
		}
		
	} 
	ll cnt = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (i == 0) {
				for (int k = 0; k < preCount[j].size(); k++) {
					int occ = preCount[j][k];
					// cout << "k : " << k << " size: " << preCount[j].size();
					// cout << "i: j:" << i << " " << j << " occ : " << occ << endl;
					cnt += occ * (occ - 1) / 2;
				}
			}
			int mk = min(preCount[i].size(), preCount[j].size());
			for (int k = 0; k < mk; k++) {
				int occ = preCount[j][k] - preCount[i][k];
				// cout << "i: j:" << i << " " << j << " occ : " << occ << endl;
				cnt += occ * (occ - 1) / 2;
			}
		}
 	}
	cout << cnt << endl;
}

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
		solve(n, a);
	}
}
/********  Main() Ends Here *************/