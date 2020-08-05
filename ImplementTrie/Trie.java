public class Trie {
    private class TrieNode {
        public TrieNode[] children;
        public boolean isWord;
        public TrieNode() {
            children = new TrieNode[26];    
        }
    }

    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        insert(word,root,0);
    }
    
    private void insert(String word, TrieNode root, int idx){
        if(idx==word.length()){
            root.isWord=true;
            return;
        }
        int index = word.charAt(idx)-'a';
        if(root.children[index]==null)
            root.children[index]=new TrieNode();
        insert(word, root.children[index], idx+1);
    }

    public boolean search(String word) {
        return search(word, root, 0, false);
    }
    
    public boolean search(String word, TrieNode root, int idx, boolean pre){
        if(idx==word.length()) {
            return pre ? true : root.isWord;
        }
        int index = word.charAt(idx)-'a';
        if(root.children[index]==null) {
            return false;
        }
        
        return search(word,root.children[index],idx+1, pre);
    }

    public boolean startsWith(String prefix) {
        return search(prefix, root, 0, true);
    }
}
