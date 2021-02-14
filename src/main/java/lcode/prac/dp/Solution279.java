package lcode.prac.dp;

import java.util.ArrayList;
import java.util.List;

// https://leetcode.com/problems/perfect-squares/
public class Solution279 {
    static List<Integer> dp = new ArrayList<>();
    static {
        dp.add(0);
    }

    public int numSquares(int n) {
        while (dp.size() <= n){
            int min = Integer.MAX_VALUE;
            int i = dp.size();
            int j = 1;
            while(i - j*j >= 0) {
                min = Math.min(min, dp.get(i - j*j) + 1);
                ++j;
            }
            dp.add(min);
        }
        return dp.get(n);
    }
}
