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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> cnt;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			cnt[a[j]] ++;
		}
		
		vector<int> cnts;
		for (auto [k, v]: cnt) {
			cnts.push_back(v);
		}
		sort(cnts.begin(), cnts.end());
		vector<int> cntvec(n+1);
		vector<int> precnt(n+1);
		vector<int> presum(n+1);
		for (int j = 0; j < cnts.size(); j++) {
			cntvec[cnts[j]]++;
		}
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				precnt[j] = 0;
			} else {
				precnt[j] = precnt[j-1] + cntvec[j] * j;
			}
			
		}
		int rest = INT_MAX;
		for (int j = 1; j <= n; j++) {
			if (cnts[j] != 0) {
				rest = min (rest, precnt[j-1] + (n - presum[j]) - (precnt[n] - precnt[j])* j);
			}
			
		}
		cout << rest << endl;
	}
	
}
/********  Main() Ends Here *************/