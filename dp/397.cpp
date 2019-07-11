class Solution {
public:
    int dfs(unsigned n, unordered_map<unsigned, int>& m)
    {
        if(n == 1)return 0;
        if(m.find(n) != m.end())return m[n];
        if(n & 1)return min(dfs(n + 1, m), dfs(n - 1, m)) + 1;
        return dfs(n >> 1, m) + 1;
    }
    
    int integerReplacement(int n) {
        unordered_map<unsigned, int> m;
        return dfs((unsigned)n, m);
    }
};
