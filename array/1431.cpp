class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        int n = c.size();
        if(!n)return {};
        int m = 0;
        for(int i = 0; i < n; ++i)
            m = max(m, c[i]);
        vector<bool> b(n);
        for(int i = 0; i < n; ++i)
            if(c[i] + e >= m)b[i] = 1;
        return b;
    }
};
