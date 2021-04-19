package codejam.y2019.r1a.c;
// Remove package line for submit

import java.util.Scanner;

class Solution {

    public static final class Trie {

        private final class TrieNode {
            private final char c;
            private final TrieNode[] next = new TrieNode[26];
            private int count = 0;
            private boolean isEmpty = true;

            public TrieNode(char c) {
                this.c = c;
            }

            public TrieNode addNext(char c) {
                if (next[c - 'A'] == null) {
                    next[c - 'A'] = new TrieNode(c);
                    isEmpty = false;
                }
                next[c - 'A'].count++;
                return next[c - 'A'];
            }

            public int getCount() {
                return count;
            }
        }

        private final TrieNode root = new TrieNode(' ');

        public void addString(String s) {
            char[] charArray = s.toCharArray();
            TrieNode current = root;
            for (int i = 0; i < charArray.length; i++) {
                char c = charArray[i];
                current = current.addNext(c);
            }
        }

    }
    
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            String[] strs = new String[N];
            Trie trie = new Trie();
            for (int j = 0; j < N; j++) {
                strs[j] = in.next();
                StringBuilder sb = new StringBuilder();
                sb.append(strs[j]);
                sb.reverse();
                trie.addString(sb.toString());
            }
            int sum = 0;
            for (Trie.TrieNode node : trie.root.next) {
                if (node != null) {
                    int[] res = countPair(node);
                    sum += res[0];
                }
            }
            System.out.println("Case #" + (i+1) + ": " + sum);
        }
        in.close();
    }

    public static int[] countPair(Trie.TrieNode node) {
        if (node.count == 1) {
            return new int[]{0, 0};
        } else if (node.count == 2) {
            return new int[]{2, 2};
        }
        Trie.TrieNode[] nodes = node.next;
        int remining = node.count;
        int count = 0;
        for (Trie.TrieNode trieNode : nodes) {
            if (trieNode != null) {
                int[] res = countPair(trieNode);
                count += res[0];
                remining -= res[1];
            }
        }
        if (remining >= 2) {
            count += 2;
            return new int[]{count, node.count - (remining - 2)};
        }
        return new int[]{count, node.count - remining};

    }
}


