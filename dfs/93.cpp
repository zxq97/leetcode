class Solution {
public:
    void dfs(int i, int n, int cnt, string& c, vector<string>& v, const string& s)
    {
        if(i == s.length() && cnt == 3){
            v.push_back(c);
            return;
        }
        if(i >= s.length() || cnt > 4)return;
        if(s[i] == '0' && c.length() && c.back() == '.'){
            if(i == s.length() - 1){
                c += "0";
                dfs(i + 1, 0, cnt, c, v, s);
                c.pop_back();
                return;
            }
            else{
                c += "0.";
                dfs(i + 1, 0, cnt + 1, c, v, s);
                c.pop_back();
                c.pop_back();
                return;
            }
        }
        else if(s[i] == '0' && !i){
            c += "0.";
            dfs(i + 1, 0, cnt + 1, c, v, s);
            return;
        }
        if(n * 10 + s[i] - '0' < (1 << 8)){
            c += s[i];
            dfs(i + 1, n * 10 + s[i] - '0', cnt, c, v, s);
            c.pop_back();
        }
        if(cnt < 3 && c.length()){
            if(c.back() == '.')return;
            c += ".";
            dfs(i, 0, cnt + 1, c, v, s);
            c.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        string c;
        dfs(0, 0, 0, c, v, s);
        return v;
    }
};
