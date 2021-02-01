// https://leetcode.com/contest/biweekly-contest-44/problems/count-ways-to-make-array-with-product/
class Solution {
    public int[] waysToFillArray(int[][] queries) {
        int[] answer = new int[queries.length];

        for (int[] querie: queries) {
        	int n = querie[0];
        	int k = querie[1];

    		// First step -> prime divide
    		// Second step -> 73  with 2 ^2 * 3 * 5 * 11 ==> 73 * 73 * 73 * (C(1, 73) + C(2, 73)) = 73 * 73 * 73 * ( C(72, 74) <=> C(2, 74) = 74 * 73 / 2)
            // https://en.wikipedia.org/wiki/Stars_and_bars_%28combinatorics%29 => give us the way to calculate
    		// General rule ==> n with a^k1 * b^k2 * ... ==> C(k1 -1, n + k1 -1) * C(k2 - 1, n + k2 - 1)

        }

    }
}