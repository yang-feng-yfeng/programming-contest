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

string solve() {
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i< n; i++) {
		cin >> p[i];
	}
	string res = "L";
	int cur = 0;
	int begin = 1;
	int end = n-1;
	int previous = 0;
	for (int i = 1; i < n; i++) {
		if ((p[cur] < p[begin] && p[cur] < p[end]) || 
			(p[cur] > p[begin] && p[cur] > p[end]))  {
			if (abs(p[cur] - p[begin]) > abs (p[cur] - p[end])) {
				res += "L";
				cur = begin;
				begin++;
			} else {
				res += "R";
				cur = end;
				end --;
			}
		} else {
			if (previous == 0) {
				res += "L";
				cur = begin;
				previous = 
				begin++;
			} else 
		}
	}
	return res;
}

/********** Main()  function *******/
int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T ; t++) {
		string res = solve();
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/