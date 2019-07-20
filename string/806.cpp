class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> v(2);
        int deep = 1, n = 0;
        for(int i = 0; i < s.length(); ++i)
            n + widths[s[i] - 'a'] > 100 ? ++deep, n =  widths[s[i] - 'a'] : n +=  widths[s[i] - 'a'];
        v[0] = deep;
        v[1] = n;
        return v;
    }
};
