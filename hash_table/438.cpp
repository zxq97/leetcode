class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m, h;
        for(int i = 0; i < p.length(); ++i)
            ++m[p[i]];
        int n = p.length();
        for(int i = 0; i < n && i < s.length(); ++i)
            ++h[s[i]];
        vector<int> ans;
        for(int i = n, j = 0; i < s.length(); ++i, ++j){
            if(h == m)ans.push_back(j);
            --h[s[j]];
            if(!h[s[j]])h.erase(s[j]);
            ++h[s[i]];
        }
        if(h == m)ans.push_back(s.length() - n);
        return ans;
    }
};
