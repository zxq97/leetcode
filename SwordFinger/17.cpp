class Solution {
public:
    vector<int> printNumbers(int n) {
        if(!n)return {};
        int m = 0;
        for(int i = 0; i < n; ++i)
            m = m * 10 + 9;
        vector<int> v(m);
        for(int i = 1; i <= m; ++i)
            v[i - 1] = i;
        return v;
    }
};
