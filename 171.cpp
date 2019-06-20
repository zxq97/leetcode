class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0, p = 0;
        for(int i = s.length() - 1; i >= 0; --i){
            int t = s[i] - 'A' + 1;
            ans += t * pow(26, p++);
        }
        return ans;
    }
};
