class Solution {
public:
    void hash(const string& pattern, unordered_map<char, int>& m, string& c)
    {
        for(int i = 0; i < pattern.length(); ++i){
            if(m.find(pattern[i]) == m.end())m[pattern[i]] = i;
            c += m[pattern[i]];
        }
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        unordered_map<char, int> m;
        string c;
        hash(pattern, m, c);
        for(int i = 0; i < words.size(); ++i){
            m.clear();
            string t;
            hash(words[i], m, t);
            if(t == c)v.push_back(words[i]);
        }
        return v;
    }
};
