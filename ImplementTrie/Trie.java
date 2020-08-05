import java.util.Scanner;

class Trie {
    private TrieNode[] children;
    
    public Trie() {
        roots = new TrieNode[26];
    }
    
    public void insert(final String word) {
        
    }

    public boolean search(final String word) {
        if (word.length() == 0) return true;
        final char first = word.charAt(0);
        if (children[first - 'a'] == null)
            return false;
        else
            return children[first - 'a'].contains(word.substring(1));
    }
    
    public boolean startsWith(final String prefix) {
        return children[prefix.charAt(0)] == null ? false : children[prefix.charAt(0)].startsWith(prefix.substring(1));
    }

    private class TrieNode {
        private TrieNode[] children;
        private final boolean end;
        private final char letter;

        public TrieNode(final char letter, final boolean end) {
            this.letter = letter;
            this.end = end;
        }
        
        public boolean contains(final String word) {
            if (word.length() == 1)
                return end;
            if (word.length() == 0) return true;
            final char first = word.charAt(0);
            if (children[first - 'a'] == null)
                return false;
            else
                return children[first - 'a'].contains(word.substring(1));
        }

        public boolean startsWith(final String pre) {
            if (pre.length() == 0)
                return true;
            else if (children[pre.charAt(0) - 'a'] != null) {
                return children[pre.charAt(0) - 'a'].startsWith(pre.substring(1));
            }
            else
                return false;
        }
    }

    public static void main(final String[] args) {
        System.out.println();
    }
}

