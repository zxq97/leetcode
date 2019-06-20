class Solution {
public:
    void f(const string& s, string& a)
    {
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); ++i){
            if(m.find(s[i]) != m.end())
                a += m[s[i]];
            else{
                a += i;
                m[s[i]] = i;
            }
        }
    }
    
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())return 0;
        string a, b;
        f(s, a);
        f(t, b);
        return a == b;
    }
};
