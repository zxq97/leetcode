class Solution {
public:
    bool checkInclusion(string s, string c) {
        if(s.length() > c.length())return 0;
        unordered_map<char, int> m, h;
        for(int i = 0; i < s.length(); ++i){
            ++m[s[i]];
            ++h[c[i]];
        }
        if(h == m)return 1;
        for(int i = 0, j = s.length(); j < c.length(); ++i, ++j){
            --h[c[i]];
            if(!h[c[i]])h.erase(c[i]);
            ++h[c[j]];
            if(h == m)return 1;
        }
        return 0;
    }
};
