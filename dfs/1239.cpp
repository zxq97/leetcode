class Solution {
public:
    bool isRepeat(const string& s)
    {
        vector<bool> b(26);
        for(int i = 0; i < s.length(); ++i){
            if(b[s[i] - 'a'])return 1;
            b[s[i] - 'a'] = 1;
        }
        return 0;
    }
    
    int dfs(int i, int v, const int n, const vector<string>& a)
    {
        if(i == n)return 0;
        if(isRepeat(a[i]))return dfs(i + 1, v, n, a);
        bool flag = 1;
        int ans = 0;
        for(int j = 0; j < a[i].length(); ++j)
            if(v & (1 << (a[i][j] - 'a'))){
                flag = 0;
                break;
            }
        if(flag){
            for(int j = 0; j < a[i].length(); ++j)
                v |= (1 << (a[i][j] - 'a'));
            ans = dfs(i + 1, v, n, a) + a[i].length();
            for(int j = 0; j < a[i].length(); ++j)
                v ^= (1 << (a[i][j] - 'a'));
        }
        return max(ans, dfs(i + 1, v, n, a));
    }
    
    int maxLength(vector<string>& a) {
        int n = a.size();
        if(!n)return 0;
        return dfs(0, 0, n, a);
    }
};
