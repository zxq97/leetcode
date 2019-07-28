class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v;
        unordered_map<char, int> m;
        unordered_set<char> se;
        for(int i = 0; i < s.length(); ++i)
            ++m[s[i]];
        for(int i = 0, j = 0; j < s.length(); ++j){
            --m[s[j]];
            se.insert(s[j]);
            if(!m[s[j]]){
                m.erase(s[j]);
                bool flag = 1;
                for(auto it : se)
                    if(m.find(it) != m.end()){
                        flag = 0;
                        break;
                    }
                if(flag){
                    se.clear();
                    v.push_back(j - i + 1);
                    i = j + 1;
                }
            }
        }
        return v;
    }
};
