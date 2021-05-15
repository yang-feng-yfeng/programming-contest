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

ll solve(vector<int> & nums) {
	unordered_map<int, int> count;
	for (int i = 0; i < nums.size(); i++) {
		count[nums[i] - i] ++;
	}
	ll res = 0;
	for (auto& e : count) {
		// cout << "e second" << e.second << endl;
		res += (ll)e.second * (e.second - 1) / 2;
 	}
	return res;
}


/********** Main()  function *******/
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> N;
		vector<int> nums(N);
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		cout << solve(nums) << endl;
	}
}
/********  Main() Ends Here *************/