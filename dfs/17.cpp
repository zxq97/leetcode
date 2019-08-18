class Solution {
public:
    void dfs(int i, string& c, const string& d, const string s[], vector<string>& v)
    {
        if(i == d.length()){
            v.push_back(c);
            return;
        }
        string t = s[d[i] - '0'];
        for(int j = 0; j < t.length(); ++j){
            c += t[j];
            dfs(i + 1, c, d, s, v);
            c.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string d) {
        if(!d.length())return {};
        string s[10];
        memset(s, 0, sizeof(s));
        s[2] = "abc";
        s[3] = "def";
        s[4] = "ghi";
        s[5] = "jkl";
        s[6] = "mno";
        s[7] = "pqrs";
        s[8] = "tuv";
        s[9] = "wxyz";
        vector<string> v;
        string c;
        dfs(0, c, d, s, v);
        return v;
    }
};
