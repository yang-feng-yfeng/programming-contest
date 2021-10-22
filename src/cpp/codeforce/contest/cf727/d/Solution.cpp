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
	vector<vector<ll>> ba(n);
	for (int i = 0; i < n ; i++) {
		cin >> ba[i][0] >> ba[i][1];
	}
	sort(ba.begin(), ba.end());
	

	
}
/********  Main() Ends Here *************/