class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(!n || n == 1)return n;
        int ans = 0;
        for(int i = 0, j = n - 1; i < j;){
            if(s[i] == s[j]){
                while(i < j && s[i + 1] == s[i])++i;
                while(i < j && s[j - 1] == s[j])--j;
                ++i;
                --j;
                if(i == j)ans = 1;
            }
            else{
                ans = j - i + 1;
                break;
            }
        }
        return ans;
    }
};
