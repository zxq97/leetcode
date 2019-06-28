class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        }
    };
    
    vector<vector<int>> allCellsDistOrder(int r, int c, int x, int y) {
        vector<vector<int>> ans(r * c, vector<int>(3));
        int idx = 0;
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j){
                ans[idx][0] = i;
                ans[idx][1] = j;
                ans[idx++][2] = abs(i - x) + abs(j - y);
            }
        sort(ans.begin(), ans.end(), cmp());
        for(int i = 0; i < ans.size(); ++i)
            ans[i].pop_back();
        return ans;
    }
};
