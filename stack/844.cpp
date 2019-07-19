class Solution {
public:
    void f(string& s, const string& c)
    {
        for(int i = 0; i < c.length(); ++i){
            if(c[i] == '#'){
                if(s.length())
                    s.pop_back();
            }
            else
                s.push_back(c[i]);
        }
    }
    
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        f(ss, s);
        f(tt, t);
        return ss == tt;
    }
};
