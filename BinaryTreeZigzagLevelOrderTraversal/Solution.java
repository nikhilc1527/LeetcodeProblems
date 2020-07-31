class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        Deque<TreeNode> currentLevel = new ArrayDeque<>(), nextLevel;
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> current;
        boolean zig = true;
        TreeNode node;
        currentLevel.add(root);
        while (!currentLevel.isEmpty()) {
            current = new ArrayList<>();
            nextLevel = new ArrayDeque<>();

            while (!currentLevel.isEmpty()) {
                node = zig ? currentLevel.pollFirst() : currentLevel.pollLast();

                if (zig) {
                    if (node.left != null) nextLevel.addLast(node.left);
                    if (node.right != null) nextLevel.addLast(node.right);
                }
                else {
                    if (node.right != null) nextLevel.addFirst(node.right);
                    if (node.left != null) nextLevel.addFirst(node.left);
                }
                current.add(node.val);
            }
            res.add(current);
            zig = !zig;
            currentLevel = nextLevel;
        }

        return res;
    }
}
