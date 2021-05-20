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
	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;

		int n = (int) log2((long double)N);
		int res = pow(2, n) - 1;
		cout << res << endl;
	}
}
/********  Main() Ends Here *************/