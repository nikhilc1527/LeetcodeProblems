import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map =  new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                return new int[] {map.get(target - nums[i]), i};
            } else {
                map.put(nums[i], i);
            }
        }
        return new int[] {};
    }

    public static void main(String[] args) {
        for (int i : new Solution().twoSum(new int[]{5, 1, 6}, 6)) {
            System.out.println(i);
            Solution s = new Solution();
            System.out.println();
            
        }
    }
}
