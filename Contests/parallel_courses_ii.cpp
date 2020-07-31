int f[1<<15];

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        const int INF = 1000000000;
        
        vector<vector<int>> v(n);
        for (auto e : dependencies)
        {
            v[e[1]-1].push_back(e[0]-1);
        }
        
        for (int s = 0; s < 1<<n; ++s) f[s] = INF;
        f[0] = 0;
        
        for (int s = 0; s < 1<<n; ++s)
        {
            if (f[s] == INF) continue;
            
            int can = 0;
            for (int i = 0; i < n; ++i)
            {
                if (s>>i&1) continue;
                int flag = 0;
                for (auto j : v[i])
                {
                    if (!(s>>j&1)) flag = 1;
                }
                if (flag == 0) can |= 1<<i;
            }
            
            for (int t = can; t; t = (t-1)&can)
            {
                if (__builtin_popcount(t) > k) continue;
                f[s|t] = min(f[s|t], f[s]+1);
                
            }
        }
        
        return f[(1<<n)-1];
    }
};
