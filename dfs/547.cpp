class Solution {
public:
    int getf(int x, vector<int>& f)
    {
        return f[x] == x ? x : f[x] = getf(f[x], f);
    }
    
    void merge(int x, int y, vector<int>& f)
    {
        int a = getf(x, f), b = getf(y, f);
        if(a != b)
            f[a] = b;
    }
    
    int findCircleNum(vector<vector<int>>& m) {
        if(!m.size() || !m[0].size())return 0;
        int n = m.size();
        vector<int> f(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(j != i && m[i][j])merge(i, j, f);
        int ans = 0;
        for(int i = 0;i < n; ++i)
            if(f[i] == i)++ans;
        return ans;
    }
};
