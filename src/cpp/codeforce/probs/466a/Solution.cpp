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

int solve(int n, int m, int a, int b) {
	int mprice = n * a;
	mprice = min(mprice, (n / m + 1) * b);
	mprice = min(mprice, (n / m ) * b + (n % m) * a);
	return mprice;
}

/********** Main()  function *******/
int main()
{
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	int res = solve(N, M, A, B);
	cout << res << endl;
	// }
}
/********  Main() Ends Here *************/