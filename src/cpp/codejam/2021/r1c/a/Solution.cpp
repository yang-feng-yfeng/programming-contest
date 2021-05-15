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

using namespace std;

double solve(int k, vector<int> & sold) {
	// seperate
	sort(sold.begin(), sold.end());
	vector<int> range;
	vector<int> separate;
	separate.push_back (sold[0] - 1);
	separate.push_back (k - sold[sold.size() -1]);
	for (int i = 1; i < sold.size(); i++) {
		if (sold[i] != sold[i-1]) {
			range.push_back(sold[i] - sold[i-1] - 1);
			separate.push_back((sold[i] - sold[i-1])/2);
		}
	}
	sort(separate.begin(), separate.end(), greater<>());
	sort(range.begin(), range.end(), greater<>());
	int maxC = 0;
	if (range.size() > 0 ) {
		maxC = max(maxC, range[0]);
	}
	maxC = max(maxC, separate[0] + separate[1]);
	return (double) maxC / k;
}

/********** Main()  function *******/
int main()
{
	int T, N, K;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> N >> K; 
		vector<int> sold(N) ;
		for (int i = 0; i < N; i++) {
			cin >> sold[i];
		}
		double res = solve(K, sold);
		cout << "Case #" << t <<": " << res << endl;
	}
}
/********  Main() Ends Here *************/