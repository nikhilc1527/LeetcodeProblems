class Solution {
    public int climbStairs(int n) {
        return climbStairs(n, new int[n]);
    }
    
    private int climbStairs(int n, int[] stairs) {
        if (n <= 1) return 1;
        else if (stairs[n - 1] > 0) return stairs[n - 1];
        else return stairs[n - 1] = climbStairs(n - 1, stairs) + climbStairs(n - 2, stairs);
    }
}
