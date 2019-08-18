class Solution {
public:
    struct cmp{
        bool operator()(const string& a, const string& b) const
        {
            return a.length() < b.length();
        }
    };
    
    bool isLink(const string& last, const string& cur)
    {
        if(cur.length() != last.size() + 1)return 0;
        bool flag = 0;
        int i = 0, j = 0;
        for(; i < last.length();){
            if(last[i] != cur[j] && flag)return 0;
            else if(last[i] != cur[j]){
                ++j;
                flag = 1;
            }
            else{
                ++i;
                ++j;
            }
        }
        if(((i == last.length() && j == cur.length())) || (i == last.length() && j == cur.length() -1 && !flag))return 1;
        return 0;
    }
    
    int dfs(int i, int last, const vector<string>& words)
    {
        if(i == words.size())return 0;
        int ans = 0;
        if(last == -1 || isLink(words[last], words[i]))
            ans = max(ans, dfs(i + 1, i, words) + 1);
        ans = max(ans, dfs(i + 1, last, words));
        return ans;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp());
        return dfs(0, -1, words);
    }
};
