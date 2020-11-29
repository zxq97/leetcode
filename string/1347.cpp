class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length(), m = t.length();
        if(n != m)return 0;
        vector<int> a(26), b(26);
        for(int i = 0; i < n; ++i){
            ++a[s[i] - 'a'];
            ++b[t[i] - 'a'];
        }
        int cnt = 0;
        for(int i = 0; i < 26; ++i)
            cnt += abs(a[i] - b[i]);
        return cnt >> 1;
    }
};
