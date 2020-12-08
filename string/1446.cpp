class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        if(!n)return 0;
        int ans = 0, cur = 1;
        for(int i = 1; i < n; ++i){
            if(s[i] == s[i - 1])++cur;
            else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        return max(ans, cur);
    }
};
