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

	int N;
	cin >> N;
	unordered_map<string, int> m;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (m[s] == 0) {
			m[s]++;
			cout << "OK" <<endl;
		} else {
			cout << s << m[s] << endl;
			m[s] ++;
		}
	}
	return 0;
}
/********  Main() Ends Here *************/