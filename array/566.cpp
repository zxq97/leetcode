class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if(!n)return {};
        int m = nums[0].size();
        if(!m)return {};
        if(!r || !c || r * c != n * m)return nums;
        vector<vector<int>> v(r, vector<int>(c));
        int x = 0, y = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                v[x][y++] = nums[i][j];
                if(y == c){
                    y = 0;
                    ++x;
                }
            }
        return v;
    }
};
