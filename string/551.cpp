class Solution {
public:
    bool checkRecord(string s) {
        bool flag = 0;
        for(int i = 0; i < s.length(); ++i){
            if(flag && s[i] == 'A')return 0;
            if(s[i] == 'A')flag = 1;
            if(i != s.length() - 2 && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')return 0;
        }
        return 1;
    }
};
