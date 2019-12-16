class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] == b[0])return a[1] < b[1];
            return a[0] < b[0];
        }
    };
    
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n = v.size();
        if(!n)return 0;
        sort(v.begin(), v.end());
        int ans = n, l = v[0][0], r = v[0][1];
        for(int i = 1; i < n; ++i){
            if(v[i][0] >= l && v[i][1] <= r)--ans;
            else{
                l = min(l, v[i][0]);
                r = max(r, v[i][1]);
            }
        }
        return ans;
    }
};
