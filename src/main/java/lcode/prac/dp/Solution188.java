package lcode.prac.dp;

public class Solution188 {
    public int maxProfit(int k, int[] prices) {
        int[][] mem = new int[prices.length + 1][k+1];

        for (int i = 1 ;  i < prices.length ; i++ ) {
            int[] maxToday = new int[k+1];
            // Sell it today
            for (int j = 0; j < i; j ++) {
                // Buy at day j
                int gain = prices[i] - prices[j];
                if (gain > 0) {
                    for (int h = 1; h <= k; h++) {
                        maxToday[h] = Math.max(maxToday[h], mem[j][h-1] + gain);
                    }
                }
            }
            // Dont trade today
            for (int h = 1; h <= k; h++) {
                maxToday[h] = Math.max(maxToday[h], mem[i][h]);
                mem[i+1][h] = maxToday[h];
            }
        }
        return mem[prices.length][k];
    }
}
