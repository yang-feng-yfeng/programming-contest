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


/********** Main()  function *******/
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t<=T; ++t ) {
		cin >> N;
		unordered_map<int, vector<int>> uscore;
		vector<int> u(N), s(N);
		for (int i = 0; i < N; i++) {
			cin >> u[i];
		}
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> s[i];
			sum += s[i];
			uscore[u[i]].push_back(s[i]);
		}
		
		for (int i = 1; i <= N; i++) {
			sort(uscore[i].begin(), uscore[i].end());
		}

		for (int i = 1; i <= N; i++) {
			vector<int> & a = uscore[i];
			int cur = 0;
			for (int j = 0; j < a.size(); j++) {
				cur += a[j];
				a[j] = cur;
			}
		}		
		for (int i = 1; i <= N; i++) {
			long long toSub = 0;
			for (int j = 1; j <= N; j++) {
				int rem = uscore[j].size() % i;
				if (rem != 0) {
					toSub += uscore[j][rem-1];
				}
			}
			cout << sum - toSub << " ";
		}
		cout << endl;
	}
}
/********  Main() Ends Here *************/