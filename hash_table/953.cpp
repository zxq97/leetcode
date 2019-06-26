class Solution {
public:
    bool isorder(const string& a, const string& b, unordered_map<char, int>& m)
    {
        for(int i = 0; i < min(a.length(), b.length()); ++i){
            if(m[a[i]] < m[b[i]])return 1;
            else if(m[a[i]] == m[b[i]])continue;
            else return 0;
        }
        return a.length() <= b.length();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for(int i = 0; i < order.length(); ++i)
            m[order[i]] = i;
        for(int i = 1; i < words.size(); ++i)
            if(!isorder(words[i - 1], words[i], m))return 0;
        return 1;
    }
};
