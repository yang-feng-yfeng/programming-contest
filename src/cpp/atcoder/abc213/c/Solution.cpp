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

int solve() {
	return 0;
}

/********** Main()  function *******/
int main()
{
	int h, w, n;
	cin >> h >> w >> n;
	vector<pair<int,int>> cord(n);
	set<int> aset;
	set<int> bset;
	map<int, int> amap;
	map<int, int> bmap;
	
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		aset.insert(a);
		bset.insert(b);
		cord[i] = make_pair(a, b);
	}
	// cout << "test : " << endl;
	int k = 1;
	for (int a: aset) {
		amap.try_emplace(a, k++);
	}
	k = 1;
	for (int b: bset) {
		bmap.try_emplace(b, k++);
	}
	for (auto cor : cord) {
		cout << amap[cor.first] << " " << bmap[cor.second] << "\n";
	}
	return 0;
}
/********  Main() Ends Here *************/