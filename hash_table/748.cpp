class Solution {
public:
    bool isSame(const vector<int>& a, const vector<int>& b)
    {
        for(int i = 0; i < a.size(); ++i)
            if(a[i] > b[i])return 0;
        return 1;
    }
    
    string shortestCompletingWord(string s, vector<string>& words) {
        vector<int> b(26);
        for(int i = 0; i < s.length(); ++i)
            if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
                ++b[tolower(s[i]) - 'a'];
        string ans;
        for(int i = 0; i < words.size(); ++i){
            vector<int> t(26);
            for(int j = 0; j < words[i].length(); ++j)
                ++t[words[i][j] - 'a'];
            if(isSame(b, t) && (words[i].length() < ans.length() || !ans.length()))
                ans = words[i];
        }
        return ans;
    }
};
