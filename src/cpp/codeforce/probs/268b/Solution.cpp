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

ll solve(int N) {
	ll count = 0; 
	for (int i = 0; i < N; i++) {
		int wrong = N - 1 - i;
		count += wrong * (i + 1);
	}
	count += N;
	return count;
}

/********** Main()  function *******/
int main()
{
	int N;
	// cin >> T;
	// for (int t = 1; t<=T; ++t ) {
	cin >> N;
	ll res = solve(N);
	cout << res << endl;
	// }
}
/********  Main() Ends Here *************/