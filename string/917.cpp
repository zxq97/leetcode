class Solution {
public:
    string reverseOnlyLetters(string s) {
        for(int i = 0, j = s.length() - 1; i < j;){
            if(isalpha(s[i]) && isalpha(s[j]))
                swap(s[i++], s[j--]);
            else if(!isalpha(s[i]))++i;
            else --j;
        }
        return s;
    }
};
