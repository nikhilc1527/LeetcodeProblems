import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqs = new HashMap<>();
	for (int i : nums) {
	    if (freqs.containsKey(i)) {
		freqs.replace(i, freqs.get(i) + 1);
	    }
	    else freqs.put(i, 1);
	}
	
	PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
	
	for (Map.Entry<Integer, Integer> 
    }
}
