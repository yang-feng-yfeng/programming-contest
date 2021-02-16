package lcode.w45;

//https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
public class Solution1749 {
    public int maxAbsoluteSum(int[] nums) {
        int maxAbs = 0;
        int maxPositiveWithEnd = 0;
        int maxNegativeWithEnd = 0;
        for (int i = 0; i< nums.length; i++) {
            if (nums[i] > 0) {
                maxPositiveWithEnd = Math.max(nums[i], maxPositiveWithEnd + nums[i]);
                maxNegativeWithEnd += nums[i];
                maxAbs = Math.max(maxAbs, maxPositiveWithEnd);
            } else {
                maxNegativeWithEnd = Math.min(nums[i], maxNegativeWithEnd + nums[i]);
                maxPositiveWithEnd += nums[i];
                maxAbs = Math.max(maxAbs, -maxNegativeWithEnd);
            }
        }
        return maxAbs;
    }
}
