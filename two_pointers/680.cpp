class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length() <= 1)return 1;
        int cnt = 0;
        int l, r;
        for(int i = 0, j = s.length() - 1; i < j; ++i, --j)
            if(s[i] != s[j]){
                if(cnt == 2)return 0;
                else if(cnt == 1){
                    ++cnt;
                    i = l;
                    j = r;
                    ++j;
                }
                else{
                    ++cnt;
                    l = i--;
                    r = j;
                }
            }
        return 1;
    }
};
