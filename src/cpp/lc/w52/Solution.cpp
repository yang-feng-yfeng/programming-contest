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
const ll mod = 1e9 + 7;
const int N = 1e5+1; 

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
		int freq[N] = { 0 };
		int preFreq[N] = { 0 };

		for (int i = 0; i < n; i++) {
			freq[nums[i]] ++; 
		}
		for (int i = 0; i < nums.size(); i++) {
			preFreq[i] = preFreq[i-1] + freq[i];
		}
		ll res = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j+= i) {
				int count = preFreq[j-1] - preFreq[j-i-1];
				res = (res + count * (j / i - 1) * freq[i] % mod) % mod;
			}
		}
		return res;
    }
};

/********** Main()  function *******/
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		string res = "test";
		cout << "Case #" << t <<": " << res << endl;
	}
}
/********  Main() Ends Here *************/