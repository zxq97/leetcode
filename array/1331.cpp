class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        int n = a.size();
        if(!n)return {};
        vector<int> v = a;
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        m[v[0]] = 1;
        for(int i = 1, j = 1; i < n; ++i){
            if(v[i] == v[i - 1])continue;
            m[v[i]] = ++j;
        }
        for(int i = 0; i < n; ++i)
            v[i] = m[a[i]];
        return v;
    }
};
