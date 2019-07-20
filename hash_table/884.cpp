class Solution {
public:
    void hash(const string& s, unordered_map<string, int>& m)
    {
        string c;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                if(c.length())
                    ++m[c];
                c = "";
                continue;
            }
            c += s[i];
        }
        if(c.length())
            ++m[c];
    }
    
    void insert(unordered_map<string, int>& ma, unordered_map<string, int>& mb, vector<string>& v)
    {
        for(auto i : ma)
            if(i.second == 1 && mb.find(i.first) == mb.end())v.push_back(i.first);
    }
    
    vector<string> uncommonFromSentences(string a, string b) {
        vector<string> v;
        unordered_map<string, int> ma, mb;
        hash(a, ma);
        hash(b, mb);
        insert(ma, mb, v);
        insert(mb, ma, v);
        return v;
    }
};
