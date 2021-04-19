package codejam.y2021.quali.d;
// Remove package line for submit

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Collectors;

class Solution2 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
    }


    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt(), n = in.nextInt(), q = in.nextInt();

        for (int i = 0; i < T; i++) {
            System.out.println("1 2 3");
            System.err.println("1 2 3");
            String medium = in.next();
            int val = Integer.parseInt(medium);
            System.err.println("val " + val);
            TreeNode root = new TreeNode(val);
            if (val == 2) {
                root.left = new TreeNode(1);
                root.right = new TreeNode(3);
            } else if (val == 1) {
                root.left = new TreeNode(2);
                root.right = new TreeNode(3);
            } else if (val == 3) {
                root.left = new TreeNode(1);
                root.right = new TreeNode(2);
            }

            for (int k = 4; k <= n; k++) {
                TreeNode tn = dfs(root, root.right, k, in, false);
                if (tn == null) {
                    dfs(root, root.left, k, in, true);
                }
            }
            List<Integer> sb = new ArrayList<>();
            dfsPrint(root, sb);

            String result = sb.stream().map(Objects::toString).collect(Collectors.joining(" "));

            System.out.println(result);
            int res = in.nextInt();
            if (res == 1) {
                // Do nothing
                // System.err.println("Case # Success!");
            }
            System.err.println("Case #" + (i+1) + ": " + result);
        }
        in.close();
    }

    public static void dfsPrint(TreeNode root, List<Integer> sb) {
        if (root == null) {
            return;
        }
        dfsPrint(root.left, sb);
        sb.add(root.val);
        dfsPrint(root.right, sb);
    }

    public static TreeNode dfs(TreeNode parent, TreeNode root, int k, Scanner in, boolean isParentBigger) {
        if (root == null) {
            return new TreeNode(k);
        }
        // DO request with parent, root, k and we know isParentBigger => parent > root
        System.out.println(root.val + " " + parent.val + " " + k);
        //System.err.println(root.val + " " + parent.val + " " + k);
        String medium = in.next();
        int val = Integer.parseInt(medium);
        System.err.println("val " + val);
        // 3 possibilities
        // medium root
        if (val == root.val) {
            if (isParentBigger) {
                TreeNode tn = dfs(root, root.left, k, in, true);
                if (root.left == null) {
                    root.left = tn;
                }
                return tn;
            } else {
                TreeNode tn = dfs(root, root.right, k, in, false);
                if (root.right == null) {
                    root.right = tn;
                }
                return tn;
            }
        } else if (val == parent.val) {
            if (isParentBigger) {
                // should not happen
                return null;
            } else {
                // should not happen
                return null;
            }
        } else if (val == k) {
            if (isParentBigger) {
                TreeNode tn = dfs(root, root.right, k, in, false);
                if (root.right == null) {
                    root.right = tn;
                }
                return tn;
            } else {
                TreeNode tn = dfs(root, root.left, k, in, true);
                if (root.left == null) {
                    root.left = tn;
                }
                return tn;
            }
        }
        return null;
    }
}
