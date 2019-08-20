class Solution {
public:
    string addStrings(string s, string c) {
        int t = 0;
        int i = s.length() - 1, j = c.length() - 1;
        for(; i >= 0 && j >= 0; --i, --j){
            int x = (s[i] - '0' + c[j] - '0' + t) % 10;
            t = (s[i] - '0' + c[j] - '0' + t) / 10;
            s[i] = x + '0';
        }
        while(i >= 0){
            int x = (s[i] - '0' + t) % 10;
            t = (s[i] - '0' + t) / 10;
            s[i--] = x + '0';
        }
        while(j >= 0){
            int x = (c[j] - '0' + t) % 10;
            t = (c[j--] - '0' + t) / 10;
            s.insert(s.begin(), x + '0');
        }
        if(t)
            s.insert(s.begin(), t + '0');
        return s;
    }
};
