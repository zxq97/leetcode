class Solution {
public:
    bool check(int i, int k, const int n, vector<int>& v, vector<bool>& b)
    {
        for(int j = 0; j < i; ++j)
            if(abs(k - v[j]) == abs(j - i))return 0;
        return 1;
    }
    
    int dfs(int i, const int n, vector<int>& v, vector<bool>& b)
    {
        if(i == n)return 1;
        int ans = 0;
        for(int j = 0; j < n; ++j)
            if(!b[j] && check(i, j, n, v, b)){
                b[j] = 1;
                v[i] = j;
                ans += dfs(i + 1, n, v, b);
                b[j] = 0;
            }
        return ans;
    }
    
    int totalNQueens(int n) {
        if(!n)return 0;
        vector<int> v(n);
        vector<bool> b(n);
        return dfs(0, n, v, b);
    }
};
