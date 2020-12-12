class Solution {
public:
    bool checkChar(const char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return 1;
        return 0;
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        if(!n || k > n || k <= 0)return 0;
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            if(checkChar(s[i]))++cnt;
            if(i >= k){
                if(checkChar(s[i - k]))--cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
