class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }
    };
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        if(!v.size())return {};
        sort(v.begin(), v.end(), cmp());
        vector<vector<int>> ans;
        int left = v[0][0], right = v[0][1];
        for(int i = 1; i < v.size(); ++i){
            if(v[i][0] >= left && v[i][0] <= right)
                right = max(right, v[i][1]);
            else{
                vector<int> t(2);
                t[0] = left;
                t[1] = right;
                ans.push_back(t);
                left = v[i][0];
                right = v[i][1];
            }
        }
        vector<int> t(2);
        t[0] = left;
        t[1] = right;
        if(!ans.size() || (ans.size() && t != ans.back()))
            ans.push_back(t);
        return ans;
    }
};
