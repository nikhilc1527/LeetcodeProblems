public class Solution {
    int widthOfBinaryTree(TreeNode root, List<BigInteger[]> maxes, int maxWidth, BigInteger ind, int level) {
	if (root == null) {
	    return;
	}

	if (maxes.size() < level) {
	    maxes.add(new BigInteger[2]);
	}

	maxes.get(level - 1)[0] = Math.min(maxes.get(level - 1)[0], ind);
	maxes.get(level - 1)[1] = Math.max(maxes.get(level - 1)[1], ind);

	maxWidth = Math.max(maxWidth, maxes.get(level - 1)[1].add(maxes.get(level - 1)[0]).add(new BigInteger(1)).intValue());

	maxWidth = Math.max(maxWidth, widthOfBinaryTree(root.left, maxes, maxWidth, ind.multiply(new BigInteger(2)), level + 1));
	maxWidth = Math.max(maxWidth, widthOfBinaryTree(root.right, maxes, maxWidth, ind.multiply(new BigInteger(2)).add(new BigInteger(1)), level + 1));

	return maxWidth;
    }
    
    public int widthOfBinaryTree(TreeNode root) {
	List<BigInteger[]> maxes = new ArrayList<>();
	return widthOfBinaryTree(root, maxes, 0, new BigInteger(1), 1);
    }
}

