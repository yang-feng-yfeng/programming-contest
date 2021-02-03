package lcode.w44;

// https://leetcode.com/contest/biweekly-contest-44/problems/count-ways-to-make-array-with-product/
class Solution1735 {
    public int[] waysToFillArray(int[][] queries) {
        int[] answer = new int[queries.length];

        for (int[] querie: queries) {
        	int n = querie[0];
        	int k = querie[1];

    		// First step -> prime divid
    		// Second step -> 73  with 2 ^2 * 3 * 5 * 11 ==> 73 * 73 * 73 * (C(1, 73) + C(2, 73)/ 2)
    		// General rule may be ==> n with a^k1 * b^k2 * ... ==> （C(1,n) + C() .... 

        }

    }
}