package lcode.w46;

// https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
public class Solution1764 {
    public boolean canChoose(int[][] groups, int[] nums) {
        int i = 0;
        int j;
        int found = 0;
        boolean noFound = false;

        for (int[] group : groups) {
            int size = group.length;
            while (i < nums.length) {
                if (nums[i] == group[0]) {
                    for (j = i; j < i + size && j < nums.length && !noFound; j++) {
                        if (group[j - i] != nums[j]) {
                            noFound = true;
                            i++;
                        }
                    }
                    if (!noFound && (j != i + size)) {
                        return false;
                    }
                    if (!noFound) {
                        i = i + size;
                        found++;
                        noFound = false;
                        break;
                    }
                    noFound = false;
                } else {
                    i++;
                }
            }
        }
        return found == groups.length;
    }
}
