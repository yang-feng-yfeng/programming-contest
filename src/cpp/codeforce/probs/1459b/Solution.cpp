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
	int n;
	cin >> n;
	if (n % 2 == 0) {
		int k = n / 2; 
		cout << (k + 1) * (k + 1) << endl;
	} else {
		int k = n / 2;
		cout << 2 * (k + 1) * (k + 2) << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/