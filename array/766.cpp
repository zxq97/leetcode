class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n <= 1)return 1;
        int m = matrix[0].size();
        if(m <= 1)return 1;
        for(int i = n - 2; i >= 0; --i){
            int x;
            for(int j = 0, k = i; k < n && j < m; ++j, ++k){
                if(!j)x = matrix[k][j];
                else if(j && matrix[k][j] != x)return 0;
            }
        }
        for(int i = 1; i < m - 1; ++i){
            int x;
            for(int j = 0, k = i; k < m && j < n; ++j, ++k){
                if(!j)x = matrix[j][k];
                else if(j && matrix[j][k] != x)return 0;
            }
        }
        return 1;
    }
};
