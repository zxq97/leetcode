class Solution {
public:
    bool canConstruct(string s, string c) {
        vector<int> v(26);
        unordered_set<char> se;
        for(int i = 0; i < s.length(); ++i){
            ++v[s[i] - 'a'];
            se.insert(s[i]);
        }
        for(int i = 0; i < c.length(); ++i)
            if(se.find(c[i]) != se.end())
                --v[c[i] - 'a'];
        for(int i : v)
            if(i > 0)return 0;
        return 1;
    }
};
