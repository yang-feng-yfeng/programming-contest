package lcode.w55;

import java.util.HashMap;
import java.util.Map;

//https://leetcode.com/problems/sum-of-unique-elements/
public class Solution1748 {
    public int sumOfUnique(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length ; i++) {
            int v = map.getOrDefault(nums[i], 0);
            map.put(nums[i], v+1);
        }
        int ret = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) {
                ret += entry.getKey();
            }
        }
        return ret;
    }
}
