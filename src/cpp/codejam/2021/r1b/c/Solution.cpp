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

using namespace std;

double dp[21][21][21][21];
int action[21][21][21][21][10];

void solve(int N, int B, int P) {
	int a = 0, b = 0, c =0 , d = 0;
	vector<int> h(N + 1, 0);
	for (int i = 0;  i < N * B; i++) {
		int next;
		cin >> next;
		int ac = action[a][b][c][d][next];
		// cerr << "ac : " << ac;
 		// cerr << "next : " << next;
		for (int k = 1; k <= N; k++) {
			if (h[k] == ac) {
				cout << k<< endl;
				cerr << k<< endl;
				if (ac == 14) {
					a++;
					b--;
				} else if (ac == 13) {
					b++;
					c--;
				} else if (ac == 12) {
					c++;
					d = 0;
				} else {
					assert (h[k] == d);
					d ++;
					if ( d == 13) {
						c++;
						d = 0;
					}
 				}
				h[k]++;
				break;
			}
			assert (k != N);
		}
	}
}


/********** Main()  function *******/
int main()
{
	int T, N, B;
	long long P;
	cin >> T >> N >> B >> P;
	assert (N == 20);
	for (int a = N; a >= 0; a--) {
		for (int b = N-a; b >= 0; b--) {
			for (int c = N-a-b; c >= 0; c--) {
				for (int d = B-3; d >= 0; d--) {
					//printf("dp[%d][%d][%d][%d] : %f\n", a, b, c, d, dp[a][b][c][d]);
					if (a +b + c == N && d != 0) {
						//printf("[%d] [%d] [%d] [%d]\n", a, b, c, d);
						continue;
					}
					
					for (int i = 0; i <= 9; i++) {
						double res = -1;
						if (b >= 1) {
							double cur = dp[a+1][b-1][c][d] + 0.1 * i;
							if (cur > res) {
								res = cur;
								action[a][b][c][d][i] = 14;
							}
						}
						if (c >= 1) {
							double cur = dp[a][b+1][c-1][d] + 0.01 * i;
							if (cur > res) {
								res = cur;
								action[a][b][c][d][i] = 13;
							}
						}
						if (a + b + c != N) {
							if (d == 12) {
								double cur = dp[a][b][c+1][0] + 0.001 * i;
								if (cur > res) {
									res = cur;
									action[a][b][c][d][i] = 12;
								}
							} else {
								double cur = dp[a][b][c][d+1] + (d == 11 ? 0.0001 * i : 0);
								if (cur > res) {
									res = cur;
									action[a][b][c][d][i] = d;
								}
							}
						}
						if (res >= 0) {
							dp[a][b][c][d] += res/10;
							//printf("action[%d][%d][%d][%d][%d] : %d\n", a, b, c, d, i, action[a][b][c][d][i]);
						}
					}					
					//printf("dp[%d][%d][%d][%d] : %f\n", a, b, c, d, dp[a][b][c][d]);
				}
			}
		}
	}	

	for (int t = 1; t<=T; ++t ) {
		solve(N, B, P);
	}
}
/********  Main() Ends Here *************/