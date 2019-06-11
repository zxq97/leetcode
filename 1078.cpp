class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> v;
        string c;
        for(int i = 0; i < text.length(); ++i){
            if(text[i] == ' '){
                v.push_back(c);
                c = "";
                continue;
            }
            c += text[i];
        }
        if(c.length())v.push_back(c);
        vector<string> ans;
        for(int i = 2; i < v.size(); ++i)
            if(v[i - 1] == second && v[i - 2] == first)
                ans.push_back(v[i]);
        return ans;
        
    }
};
