package kickstart.y2020.ra.d;
// Remove package line for submit

import java.util.*;

class Solution {

    public static final class Trie {

        private static final class TrieNode {
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
            int K = in.nextInt();

            Trie trie = new Trie();

            for (int n = 0; n < N; n++) {
                String txt = in.next();
                trie.addString(txt);
            }

            int sum = 0;
            for (Trie.TrieNode trieNode : trie.root.next) {
                // dfs
                int[] res = dfs(trieNode, 1, K);
                sum += res[0];
            }
            System.out.println("Case #" + (i+1) + ": " + sum);
        }
        in.close();
    }

    private static int[] dfs(Trie.TrieNode trieNode, int score, int K) {
        if (trieNode == null || trieNode.getCount() < K) {
            return new int[] {0, 0};
        }
        if (trieNode.isEmpty) {
            int nbPair = trieNode.getCount() / K;
            return new int[]{nbPair * score, nbPair * K};
        }
        int currentCount = trieNode.getCount();
        int sum = 0;
        for (Trie.TrieNode nextNode : trieNode.next) {
            int[] res = dfs(nextNode, score + 1, K);
            currentCount -= res[1];
            sum += res[0];
        }
        int nbPair = currentCount / K;
        sum += nbPair * score;
        return new int[]{sum, trieNode.getCount() - (currentCount % K)};
    }
}

