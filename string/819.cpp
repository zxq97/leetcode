class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s;
        for(int i = 0; i < banned.size(); ++i)
            s.insert(banned[i]);
        unordered_map<string, int> m;
        m.clear();
        string c;
        for(int i = 0; i < paragraph.length(); ++i){
            if(!isalpha(paragraph[i])){
                if(c.length() && s.find(c) == s.end())
                    ++m[c];
                c = "";
            }
            else{
                paragraph[i] = tolower(paragraph[i]);
                c += paragraph[i];
            }
        }
        if(c.length() && s.find(c) == s.end())
            ++m[c];
        int cnt = 0;
        for(auto i : m)
            if(i.second > cnt){
                c = i.first;
                cnt = i.second;
            }
        return c;
    }
};
