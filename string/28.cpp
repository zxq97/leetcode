class Solution {
public:
    int strStr(string s, string t) {
        if(s.length() < t.length())return -1;
        if(!t.length())return 0;
        for(int i = 0; i <= s.length() - t.length(); ++i){
            if(s[i] == t[0]){
                bool flag = 1;
                for(int j = 1; j < t.length(); ++j)
                    if(s[i + j] != t[j]){
                        flag = 0;
                        break;
                    }
                if(flag)return i;
            }
        }
        return -1;
    }
};
