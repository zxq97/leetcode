class Solution {
public:
    bool isSubstr(const string& s, const string& c)
    {
        for(int i = 0; i <= s.length() - c.length(); ++i)
            if(s[i] == c[0]){
                bool flag = 1;
                for(int j = 1; j < c.length(); ++j)
                    if(s[i + j] != c[j]){
                        flag = 0;
                        break;
                    }
                if(flag)return 1;
            }
        return 0;
    }
    
    int repeatedStringMatch(string a, string b) {
        int ans = 1;
        bool flag = 0;
        const string s = a;
        unordered_map<char, int> m;
        for(int i = 0; i < a.length(); ++i)
            ++m[a[i]];
        for(int i = 0; i < b.length(); ++i)
            if(m.find(b[i]) == m.end())return -1;
        while(a.length() < b.length()){
            a += s;
            ++ans;
        }
        if(isSubstr(a, b))
            flag = 1;
        while(!flag && a.length() <= (b.length() << 1)){
            if(isSubstr(a, b)){
                flag = 1;
                break;
            }
            a += s;
            ++ans;
        }
        if(isSubstr(a, b))flag = 1;
        if(!flag){
            a += s;
            flag = isSubstr(a, b);
            ++ans;
        }
        return flag ? ans : -1;
    }
};
