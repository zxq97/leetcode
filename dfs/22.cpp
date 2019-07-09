class Solution {
public:
    void dfs(int i, int x, int y, const int n, string& c, vector<string>& v)
    {
        if(i == (n << 1 ) && x == n && y == n){
            v.push_back(c);
            return;
        }
        if(x < y)return;
        if(x < n){
            c.push_back('(');
            dfs(i + 1, x + 1, y, n, c, v);
            c.pop_back();
        }
        if(y < n){
            c.push_back(')');
            dfs(i + 1, x, y + 1, n, c, v);
            c.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if(!n)return {};
        vector<string> v;
        string c;
        dfs(0, 0, 0, n, c, v);
        return v;
    }
};
