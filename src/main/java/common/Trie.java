package common;

public final class Trie {

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
