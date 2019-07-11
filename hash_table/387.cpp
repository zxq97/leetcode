class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> v(26, -1);
        for(int i = 0; i < s.length(); ++i){
            if(v[s[i] - 'a'] == -1)v[s[i] - 'a'] = i;
            else if(v[s[i] - 'a'] > -1)v[s[i] - 'a'] = n;
        }
        int ans = n;
        for(int i : v)
            if(i > -1 && i != n)
                ans = min(ans, i);
        return ans == n ? -1 : ans;
    }
};
