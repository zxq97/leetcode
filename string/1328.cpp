class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(n <= 1)return "";
        bool flag = 0;
        for(int i = 0; i < (n >> 1); ++i)
            if(s[i] != 'a'){
                s[i] = 'a';
                flag = 1;
                break;
            }
        if(!flag)s[n - 1] = 'b';
        return s;
    }
};
