package lcode.w48;

import java.util.*;

public class Solution1799 {

    public int maxScore(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> gcdVal = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ( i != j)
                    gcdVal.put( (1 << j) + (1 << i), gcd(nums[i], nums[j]));
            }
        }

        int[] dp = new int[1 << n];

        for (int i = 0; i < (1 << n); i++) {
            int bits = Integer.bitCount(i);
            if (bits % 2 != 0) {
                continue;
            }
            for (int k : gcdVal.keySet()) {
                if ( (k & i) != 0)
                    continue;
                dp[i ^ k] = Math.max(dp[i^k], dp[i] + gcdVal.get(k) * (bits / 2 + 1));
            }
        }
        return dp[(1<<n) - 1];
    }

    private int gcd( int num1, int num2) {
        // Num1 < num2
        if (num1 > num2) {
            int tmp = num1;
            num1 = num2;
            num2 = tmp;
        }
        int num3 = num2 % num1;
        while (num3 != 0) {
            num2 = num1;
            num1 = num3;
            num3 = num2 % num1;
        }
        return num1;
    }

}
