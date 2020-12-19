class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        int n = a.size();
        if(!n)return 0;
        map<int, int> m;
        for(int i = 0; i < n; ++i)
            ++m[a[i]];
        vector<int> v;
        for(auto it : m)
            v.push_back(it.second);
        sort(v.begin(), v.end());
        int ans = v.size();
        for(int i = 0; i < v.size(); ++i){
            k -= v[i];
            if(k >= 0)--ans;
            else break;
        }
        return ans;
    }
};
