class Solution {
public:
    int dfs(int i, vector<bool>& b)
    {
        if(i == b.size())return 1;
        int ans = 0;
        for(int j = 1; j < b.size(); ++j)
            if(!b[j] && (j % i == 0 || i % j == 0)){
                b[j] = 1;
                ans += dfs(i + 1, b);
                b[j] = 0;
            }
        return ans;
            
    }
    
    int countArrangement(int n) {
        vector<bool> b(n + 1);
        return dfs(1, b);
    }
};
