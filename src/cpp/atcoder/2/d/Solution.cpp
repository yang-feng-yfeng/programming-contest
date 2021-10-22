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

int getCurValue(int value, vector<int> & curValue) {
	if (curValue[value] == 0) {
		return value; 
	} else {
		int newV = getCurValue(curValue[value], curValue);
		if (newV != curValue[value]) {
			curValue[value] = newV;
		}
		return curValue[value];
	}
}

/********** Main()  function *******/
int main()
{
	int N;
	cin >> N;
	vector<int> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int K = 2e5;
	vector<int> curValue(K+1, 0);
	// if curV = 0, curV = idx;
	map<int, int> valueCnt;
	ll res = 0;

	// N odd -> mid, N even -> left = N/2-1, right = N/2;
	if (N % 2 == 1) {
		int mid = N / 2;
		for (int i = 1; i <= N/2; i++) {
			int left = mid - i;
			int right = mid + i;
			if (a[left] != a[right]) {
				valueCnt[a[left]]++;
				valueCnt[a[right]]++;		
			}
		}

		for (int i = 1; i <= N / 2; i++) {
			int left = mid - i;
			int right = mid + i;
			int lcur = getCurValue(a[left], curValue);
			int rcur = getCurValue(a[right], curValue);
			if (lcur != rcur) {
				if (valueCnt[lcur] > valueCnt[rcur]) {
					curValue[lcur] = rcur;
				} else {
					curValue[rcur] = lcur;
				}
				res ++;
			}
		}
	} else {
		int right = N / 2;
		int left = right - 1;
		for (int i = 0; i < N/2; i++) {
			int nleft = left - i;
			int nright = right + i;
			if (a[nleft] != a[nright]) {
				valueCnt[a[nleft]]++;
				valueCnt[a[nright]]++;		
			}
		}

		for (int i = 0; i < N / 2; i++) {
			int nleft = left - i;
			int nright = right + i;
			int lcur = getCurValue(a[nleft], curValue);
			int rcur = getCurValue(a[nright], curValue);
			if (lcur != rcur) {
				if (valueCnt[lcur] > valueCnt[rcur]) {
					curValue[lcur] = rcur;
				} else {
					curValue[rcur] = lcur;
				}
				res ++;
			}
		}
	}
	cout << res << endl;

}
/********  Main() Ends Here *************/