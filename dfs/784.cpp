class Solution {
public:
    void dfs(int i, string& s, vector<string>& v)
    {
        if(i == s.length()){
            v.push_back(s);
            return;
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = toupper(s[i]);
            dfs(i + 1, s, v);
            s[i] = tolower(s[i]);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = tolower(s[i]);
            dfs(i + 1, s, v);
            s[i] = toupper(s[i]);
        }
        dfs(i + 1, s, v);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        dfs(0, s, v);
        return v;
    }
};
