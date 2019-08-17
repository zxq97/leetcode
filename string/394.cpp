class Solution {
public:
    pair<string, int> dfs(int i, const string& s)
    {
        int cnt = 0;
        string t;
        pair<string, int> p;
        for(int j = i + 1; j < s.length(); ++j){
            if(s[j] >= '0' && s[j] <= '9')
                cnt = cnt * 10 + s[j] - '0';
            else if(s[j] == '['){
                p = dfs(j, s);
                string c = p.first;
                t += p.first;
                for(int k = 1; k < cnt; ++k)
                    t += c;
                j = p.second;
                cnt = 0;
            }
            else if(s[j] == ']'){
                p.second = j;
                break;
            }
            else
                t += s[j];
        }
        p.first = t;
        return p;
    }
    
    string decodeString(string s) {
        if(!s.length())return s;
        s.insert(s.begin(), '[');
        s.push_back(']');
        return dfs(0, s).first;
    }
};
