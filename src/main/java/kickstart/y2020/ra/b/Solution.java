package kickstart.y2020.ra.b;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            int K = in.nextInt();
            int P = in.nextInt(); // to pick

            int[][] sumPlats = new int[N][K+1];
            int[][] dp = new int[N+1][P+1];
            for (int i1 = 0; i1 < N; i1++) {
                int sum = 0;
                sumPlats[i1][0] = sum;
                for (int i2 = 1; i2 <= K; i2++) {
                    sum += in.nextInt();
                    sumPlats[i1][i2] = sum;
                }
            }

            for (int i1 = 1; i1 <= N; i1++) {
                for (int i2 = 0; i2 < P + 1; i2++) {
                    dp[i1][i2] = 0;
                    for (int j = 0; j <= Math.min(K, i2); j++) {
                        dp[i1][i2] = Math.max(dp[i1][i2], sumPlats[i1-1][j] + dp[i1 - 1][i2-j]);
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + dp[N][P]);
        }
        in.close();
    }
}
