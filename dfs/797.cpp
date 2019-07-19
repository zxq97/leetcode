class Solution {
public:
    void dfs(int i, const vector<vector<bool>>& e, vector<int>& v, vector<vector<int>>& ans, vector<bool>& b)
    {
        if(i == e.size() - 1){
            ans.push_back(v);
            return;
        }
        for(int j = 0; j < b.size(); ++j)
            if(!b[j] && e[i][j]){
                b[j] = 1;
                v.push_back(j);
                dfs(j, e, v, ans, b);
                v.pop_back();
                b[j] = 0;
            }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> e(n, vector<bool>(n));
        for(int i = 0; i < n; ++i)
            e[i][i] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < graph[i].size(); ++j)
                e[i][graph[i][j]] = 1;
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(0);
        vector<bool> b(n);
        b[0] = 1;
        dfs(0, e, v, ans, b);
        return ans;
    }
};
