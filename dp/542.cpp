class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n)return {};
        int m = matrix[0].size();
        if(!m)return {};
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(matrix[i][j])matrix[i][j] = 0x7fffffff - 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(matrix[i][j]){
                    if(matrix[i][j]){
                        if(i > 0)matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                        if(j > 0)matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                    }
                }
        for(int i = n - 1; i >= 0; --i)
            for(int j = m - 1; j >= 0; --j)
                if(matrix[i][j]){
                    if(i < n - 1)matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
                    if(j < m - 1)matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                }
        return matrix;
    }
};
