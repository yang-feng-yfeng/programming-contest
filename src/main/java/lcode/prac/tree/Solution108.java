package lcode.prac.tree;
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
public class Solution108 {
     public static class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode() {}
         TreeNode(int val) { this.val = val; }
         TreeNode(int val, TreeNode left, TreeNode right) {
             this.val = val;
             this.left = left;
             this.right = right;
         }
     }

    public TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length);
    }


    public TreeNode sortedArrayToBST(int[] nums, int from, int to) {
        if (from >= to) {
            return null;
        }
        int mid = (to + from) / 2;
        TreeNode l = sortedArrayToBST(nums, from, mid);
        TreeNode r = sortedArrayToBST(nums, mid + 1, to);
        return new TreeNode(nums[mid], l, r);
    }

}
