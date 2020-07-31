public class Solution {
    boolean dfs(char[][] board, int i, int j, String word, boolean[][] visited) {
	if (word.length() == 0) return true;
	if (i < 0 || i >= board.length || j < 0 || j >= board[0].length) return false;
	if (visited[i][j]) return false;
	if (board[i][j] != word.charAt(0)) return false;
	visited[i][j] = true;
	boolean res =
	    dfs(board, i - 1, j, word.substring(1, word.length()), visited) ||
	    dfs(board, i + 1, j, word.substring(1, word.length()), visited) ||
	    dfs(board, i, j + 1, word.substring(1, word.length()), visited) ||
	    dfs(board, i, j - 1, word.substring(1, word.length()), visited);
	visited[i][j] = false;
	var a = false;
	var b = 5;
	return res;
    }
  
    boolean exist(char[][] board, String word) {
	boolean[][] visited = new boolean[board.length][board[0].length];
	for (int i = 0; i < board.length; i++) {
	    for (int j = 0; j < board[i].length; j++) {
		if (dfs(board, i, j, word, visited)) return true;
	    }
	}
	return false;
    }

    public static void main(String[] args) {
	char[][] board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	String target = "ABCCED";
	new Solution().exist(board, target);
        target = "SEE";
	new Solution().exist(board, target);
	target = "ABCB";
	new Solution().exist(board, target);
    }
}
