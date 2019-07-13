class Solution {
public:
    int maxCount(int n, int m, vector<vector<int>>& ops) {
        int x = n, y = m;
        for(int i = 0; i < ops.size(); ++i){
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        return x * y;
    }
};
