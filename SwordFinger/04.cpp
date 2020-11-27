class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& v, int target) {
        int n = v.size();
        if(!n)return 0;
        int m = v[0].size();
        if(!m)return 0;
        for(int i = 0, j = m - 1; i < n && j >= 0;){
            if(v[i][j] > target)--j;
            else if(v[i][j] < target)++i;
            else return 1;
        }
        return 0;
    }
};
