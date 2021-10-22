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
	int n, s;
	cin >> n >> s;
	// starting with 1, N-1 1, rest S - (N-1);
	int rest = s - (n - 1);
	if (rest > n) {
		cout << "YES" << endl;
		for (int i = 0; i < n-1; i++) {
			cout << "1 " ;
		}
		cout << rest << endl;
		cout << rest - 1 << endl;
	} else {
		cout << "NO" << endl;
	}
	// cout << res << endl;
}
/********  Main() Ends Here *************/