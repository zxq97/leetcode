class Solution {
public:
    string convertToBase7(int num) {
        bool flag = 0;
        if(num < 0)flag = 1;
        num = abs(num);
        string s;
        do{
            s += num % 7 + '0';
            num /= 7;
        }while(num);
        if(flag)s += '-';
        reverse(s.begin(), s.end());
        return s;
    }
};
