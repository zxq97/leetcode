class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if(n == 1)return 1;
        if(word[0] >= 'a' && word[0] <= 'z'){
            for(int i = 1; i < n; ++i)
                if(word[i] >= 'A' && word[i] <= 'Z')return 0;
            return 1;
        }
        bool flag = (word[1] >= 'a' && word[1] <= 'z') ? 1 : 0;
        for(int i = 2; i < n; ++i){
            if(flag && word[i] >= 'A' && word[i] <= 'Z')return 0;
            if(!flag && word[i] >= 'a' && word[i] <= 'z')return 0;
        }
        return 1;
    }
};
