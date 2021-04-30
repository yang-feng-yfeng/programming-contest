package binarysearch.w56;

import java.util.*;

public class Solution {
    public boolean solve1(String s) {
        Map<Integer, Integer> count = new HashMap<>();
        char[] ca = s.toCharArray();
        for (int i = 0; i < ca.length; i++) {
            int c = count.getOrDefault((int)ca[i], 0);
            count.put((int)ca[i],c+1 );
        }
       if (count.keySet().size() == 1) {
            return ( count.values().iterator().next() - 2 ) % 3 == 0;
        } else {
            boolean pair = false;
            for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
                int v = entry.getValue();
                if (!pair && (v - 2) % 3 == 0) {
                    pair = true;
                } else if (v % 3 != 0) {
                    return false;
                }
            }
            return pair;
        }
    }

    public int solve2(String[] words) {
        Trie trie = new Trie();
        for (String w: words) {
            trie.addString(w);
        }

        int max = 0;
        for (Trie.TrieNode n : trie.root.getNext()) {
            if (n != null) {
                max = Math.max(max, getMax(n, n.isLast ? 1 : 0));
            }
        }
        return max;
    }

    public int getMax(Trie.TrieNode trieNode, int curr) {
        int max = curr;
        for (Trie.TrieNode tn : trieNode.getNext()) {
            if (tn != null) {
                max = Math.max(max, getMax(tn, tn.isLast ? curr + 1: 0));
            }
        }
        return max;
    }

    public int[] solve3(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length ; i++) {
            if ( i == 0) {
                if (nums[i] > nums[i+1]) {
                    res.add(nums[i]);
                }
            } else if (i == nums.length - 1) {
                if (nums[i] > nums[i-1])
                    res.add(nums[i]);
            } else {
                if ((nums[i] > nums[i-1] && nums[i] >= nums[i+1]) ||
                        (nums[i] > nums[i+1] && nums[i] >= nums[i-1])) {
                    res.add(nums[i]);
                }
            }
        }


        int[] result = new int[res.size()];
        res.sort(Comparator.naturalOrder());
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }

    public int solve4(Tree root) {
        int lv = solve(root.left, root.val, Integer.MAX_VALUE, 0);
        int rv = solve(root.right, root.val, Integer.MAX_VALUE, 0);
        return Math.max(lv, rv);
    }

    public int solve(Tree node, int lastV, int diff, int curr) {
        if (node == null) {
            return curr;
        }
        int lv = solve(node.left, node.val, node.val - lastV, (node.val - lastV) == diff || diff == Integer.MAX_VALUE ? curr+1 : 0);
        int rv = solve(node.right, node.val, node.val - lastV, (node.val - lastV) == diff || diff == Integer.MAX_VALUE ? curr+1 : 0);
        return Math.max(lv, rv);
    }

}

final class Tree {
    int val;
    Tree left;
    Tree right;
  }

final class Trie {

    public static final class TrieNode {
        public final char c;
        private final TrieNode[] next = new TrieNode[26];
        private int count = 0;
        public boolean isLast = false;

        public TrieNode(char c) {
            this.c = c;
        }

        public TrieNode addNext(char c) {
            if (next[c - 'a'] == null) {
                next[c - 'a'] = new TrieNode(c);
            }
            next[c - 'a'].count++;
            return next[c - 'a'];
        }

        public int getCount() {
            return count;
        }

        public TrieNode[] getNext() {
            return next;
        }
    }

    public final TrieNode root = new TrieNode(' ');

    public void addString(String s) {
        char[] charArray = s.toCharArray();
        TrieNode current = root;
        for (int i = 0; i < charArray.length; i++) {
            char c = charArray[i];
            current = current.addNext(c);
            if (i == charArray.length - 1) {
                current.isLast = true;
            }
        }
    }

}
