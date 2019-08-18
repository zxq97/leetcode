class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b) const
        {
            if(a[0] == b[0])return a[1] < b[1];
            return a[0] > b[0];
        }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(!people.size())return {};
        vector<vector<int>> ans;
        vector<int> v;
        sort(people.begin(), people.end(), cmp());
        for(int i = 0; i < people.size(); ++i){
            v = people[i];
            ans.insert(ans.begin() + v[1], v);
        }
        return ans;
    }
};
