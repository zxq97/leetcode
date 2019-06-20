class Solution {
public:
    int addDigits(int num) {
        if(num >= 0 && num < 10)return num;
        string s = to_string(num);
        num = 0;
        for(int i = 0; i < s.length(); ++i)
            num += s[i] - '0';
        return addDigits(num);
    }
};
