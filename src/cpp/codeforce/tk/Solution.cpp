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

int64_t add(int32_t a1, int32_t a2, int32_t * a3, int32_t a4) {
    int32_t * v1 = (int32_t *)(4 * (int64_t)a2 + (int64_t)a3); // 0xb19
    int32_t v2 = *v1 + a1; // 0xb1e
    int32_t v3 = v2 / 10; // 0xb4c
    *v1 = -10 * v3 + v2;
    if (v2 < 10) {
        // 0xbc7
        return 0;
    }
    int32_t v4 = a2 + 1; // 0xba8
    int64_t result = v4; // 0xbae
    if (v4 < a4) {
        // 0xbb0
        result = add(v3, v4, a3, a4);
    }
    // 0xbc7
    return result;
}

void print(int64_t v1, int64_t v2, int32_t v3) {
	cout << v1  << " " << v2 << " " << v3;
}

/********** Main()  function *******/
int main()
{
	int64_t v1;
	memset(&v1, 0, 3);
	int64_t v2;
	memset(&v2, 0, 5);
	v1 = 2;
	int32_t v3 = 9;
	v2 = 5;
	// ll t = 3600*24*365;
    ll t = 3;
	while (t--) {
		add(2, 0, (int32_t *)&v1, 3);
        add(3, 0, &v3, 4);
        add(7, 0, (int32_t *)&v2, 5);
		print(v1, v3, v2);
	}
}
/********  Main() Ends Here *************/