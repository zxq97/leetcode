class Solution {
public:
    int getMaxArea(const vector<int>& v)
    {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i < v.size(); ++i){
            while(!s.empty() && v[i] <= v[s.top()]){
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                ans = max(ans, (i - k - 1) * v[j]);
            }
            s.push(i);
        }
        while(!s.empty()){
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                ans = max(ans, (int)(v.size() - k - 1) * v[j]);
            }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(!n)return 0;
        int m = matrix[0].size();
        if(!m)return 0;
        vector<int> v(m);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)
                v[j] = matrix[i][j] == '0' ? 0 : v[j] + 1;
            ans = max(ans, getMaxArea(v));
        }
        return ans;
    }
};
