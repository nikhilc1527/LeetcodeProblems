class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        
        if(n < m * k) return -1;
        
        int min = (int) 1e9, max = 1;
        
        for(int day : bloomDay) {
            min = Math.min(min, day);
            max = Math.max(max, day);
        }
        
        while(min < max) {
            int mid = min + (max - min) / 2;
            if(hasBouquets(bloomDay, m, k, mid)) 
                max = mid;
            else min = mid + 1;
        }
        return min;
    }

    boolean hasBouquets(int[] bloomDay, int m, int k, int day) {
        int left = bloomDay.length, flowers = 0;
        
        for(int i = 0; i < bloomDay.length; i++) {
            int d = bloomDay[i];
            left--;
            
            if(d <= day) {
                flowers++;
            } 
            else {
                m -= flowers / k;
                
                if(m <= 0) 
                    return true;
                
                if(left < m * k) 
                    return false;
                
                flowers = 0;
            }
        }
        return flowers / k >= m;
    }
}
