class Solution {
public:
    void f(const string& str, vector<string>& v)
    {
        string s;
        for(int i = 0; i < str.length(); ++i){
            if(str[i] == ' '){
                v.push_back(s);
                s = "";
                continue;
            }
            s += str[i];
        }
        if(s.length())
            v.push_back(s);
    }
    
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        unordered_set<string> s;
        vector<string> v;
        f(str, v);
        if(pattern.length() != v.size())return 0;
        for(int i = 0; i < pattern.length(); ++i){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != v[i])return 0;
            }
            else{
                m[pattern[i]] = v[i];
                if(s.find(v[i]) != s.end())return 0;
                s.insert(v[i]);
            }
        }
        return 1;
        
    }
};
