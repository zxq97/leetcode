class Solution {
public:
    bool isMake(const string& s, const vector<int>& v)
    {
        vector<int> a(26);
        for(int i = 0; i < s.length(); ++i)
            ++a[s[i] - 'a'];
        for(int i = 0; i < a.size(); ++i)
            if(a[i] > v[i])return 0;
        return 1;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26);
        for(int i = 0; i < chars.length(); ++i)
            ++v[chars[i] - 'a'];
        int ans = 0;
        for(int i = 0; i < words.size(); ++i)
            if(isMake(words[i], v))ans += words[i].size();
        return ans;
    }
};
