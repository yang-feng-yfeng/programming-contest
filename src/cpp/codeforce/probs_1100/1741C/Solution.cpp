#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = l; i <= r; i++)

const int MAXN = 2020;

int n;
int arr[MAXN];

int go(int i, int sum) {
	if (i == n) return 0;
	for (int j = i + 1, cur = 0; j <= n; ++j) {
		cur += arr[j - 1];
		if (cur > sum) return n;
		if (cur == sum) return max(j - i, go(j, sum));
	}
	return n;
}

int solve() {
	cin >> n;
	int ans = n;
	for (int len = 1, sum = 0; len < n; ++len) {
		sum += arr[len - 1];
		ans = min(ans, go(0, sum));
	}
	return ans;
}


// ll solve() {
//   int n;
//   cin >> n;
//   vector<int> a(n);
//   vector<ll> preSum(n, 0LL);  // including itself
//   ll sum = 0;
//   rep(i, 0, n - 1) {
//     cin >> a[i];
//     sum += static_cast<ll>(a[i]);
//     if (i == 0) {
//       preSum[i] = a[i];
//     } else {
//       preSum[i] = preSum[i - 1] + a[i];
//     }
//   }

//   // iterate over the first segment length
//   int res = n;
//   rep(i, 1, n) {
//     int tmpRes = i;
//     ll segSum = preSum[i - 1];
//     if (sum % segSum != 0) continue;
// 	int lastIdx = i-1;
// 	int curIdx = i;
//     // iterate over the remining to confirm it's possible
//     while (curIdx <= n-1) {
// 		if (preSum[curIdx] - preSum[lastIdx] < segSum) {
// 			curIdx++;
// 		} else if (preSum[curIdx] - preSum[lastIdx] == segSum) {
// 			tmpRes = max(tmpRes, curIdx - lastIdx);
// 			// cout << "tmp Res: " << tmpRes << endl;
// 			lastIdx = curIdx;
// 			curIdx = lastIdx + 1;
// 		} else {
// 			break;
// 		}
//     }
// 	if (lastIdx != curIdx - 1 || curIdx <= n-1) {
// 		continue;
// 	}
// 	res = min(res, tmpRes);
//   }
//   return res;
// }

/********** Main()  function *******/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    ll res = solve();
    cout << res << endl;
  }
}
/********  Main() Ends Here *************/