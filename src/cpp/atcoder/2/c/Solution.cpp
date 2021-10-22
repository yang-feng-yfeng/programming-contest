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
	vector<int> a(N);
	for (int i = 0; i < N ; i++) {
		cin >> a[i];
	}
	map<int, int> cnt;
	int curAllCnt = 0;
	ll res = 0;
	for (int i = 0; i< N; i++) {
		res += curAllCnt - cnt[a[i]];
		curAllCnt ++;
		cnt[a[i]]++;
	}
	cout << res << endl;
}
/********  Main() Ends Here *************/