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
#include <unordered_set>


using namespace std;
using ll = long long;

int solve() {
	return 0;
}

/********** Main()  function *******/
int main()
{
	int n;
	cin >> n;
	unordered_set<string> set;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		set.emplace(s + " " + t);
	} 

	if (set.size() == n) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}
/********  Main() Ends Here *************/