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

/********** Main()  function *******/
int main()
{
	int T, N;
	int n, m, k;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> n >> m >> k;
		
		int maxi = max((n-1) + n * (m-1), ((m-1) + m * (n-1)));
		int mini = min(m, n);
		int minres = (1 + mini - 1)* (mini - 1) / 2 + (2 + mini)* (mini - 1) / 2  + (max(m, n) - mini) * mini;
		// cout << "min:" << minres << endl;
		cout << ((k <= maxi && k >= minres)? "YES" : "NO")  << endl;
	}
}
/********  Main() Ends Here *************/