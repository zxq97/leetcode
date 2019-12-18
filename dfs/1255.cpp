class Solution {
public:
    int dfs(int i, const vector<string>& words, vector<int>& v, const vector<int>& score)
    {
        if(i == words.size())return 0;
        int ans = 0;
        vector<int> c(26);
        for(int j = 0; j < words[i].length(); ++j)
            ++c[words[i][j] - 'a'];
        bool flag = 1;
        for(int j = 0; j < 26; ++j)
            if(v[j] < c[j]){
                flag = 0;
                break;
            }
        ans = dfs(i + 1, words, v, score);
        if(flag){
            int s = 0;
            for(int j = 0; j < 26; ++j){
                v[j] -= c[j];
                s += score[j] * c[j];
            }
            ans = max(ans, dfs(i + 1, words, v, score) + s);
            for(int j = 0; j < 26; ++j)
                v[j] += c[j];
        }
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        if(!words.size() || !letters.size())return 0;
        vector<int> v(26);
        for(int i = 0; i < letters.size(); ++i)
            ++v[letters[i] - 'a'];
        return dfs(0, words, v, score);
    }
};
