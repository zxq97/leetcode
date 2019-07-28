class Solution {
public:
    void f(const string& s, unordered_map<string, int>& m)
    {
        int cnt = 0, i = 0;
        for(; i < s.length() && s[i] >= '0' && s[i] <= '9'; ++i)
            cnt = cnt * 10 + s[i] - '0';
        string t;
        for(int j = s.length() - 1; j > i && s[j] != ' '; --j){
            if(s[j] == '.'){
                string c = t;
                reverse(c.begin(), c.end());
                m[c] += cnt;
            }
            t += s[j];
        }
        reverse(t.begin(), t.end());
        m[t] += cnt;
    }
    
    vector<string> subdomainVisits(vector<string>& v) {
        vector<string> ans;
        unordered_map<string, int> m;
        for(int i = 0; i < v.size(); ++i)
            f(v[i], m);
        for(auto i : m){
            string t;
            t += to_string(i.second);
            t += " ";
            t += i.first;
            ans.push_back(t);
        }
        return ans;
    }
};
