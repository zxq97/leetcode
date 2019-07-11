class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); ++i)
            ++m[s[i]];
        char c;
        for(int i = 0; i < t.length(); ++i){
            --m[t[i]];
            if(m.find(t[i]) == m.end() || m[t[i]] < 0){
                c = t[i];
                break;
            }
        }
        return c;
    }
};
