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
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	for (int i = 0; i < N ; i++) {
		cin >> A[i];
	}

	int all = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			all += A[i-1];
		} else {
			all += A[i-1]-1;
		}
	}
	cout << ((all > X) ? "No" : "Yes") <<  "\n";
	return 0;
}
/********  Main() Ends Here *************/