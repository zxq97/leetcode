class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b)const
        {
            return a[0] - a[1] < b[0] - b[1];
        }
    };
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp());
        int ans = 0;
        bool flag = 0;
        for(int i = 0; i < costs.size(); ++i){
            if(i == costs.size() >> 1)flag = 1;
            if(flag)ans += costs[i][1];
            else ans += costs[i][0];
        }
        return ans;
    }
};
