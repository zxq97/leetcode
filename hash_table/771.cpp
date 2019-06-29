class Solution {
public:
    int numJewelsInStones(string j, string s) {
        bool b[26 << 1];
        memset(b, 0, sizeof(b));
        int ans = 0;
        for(int i = 0; i < j.length(); ++i){
            if(j[i] >= 'a' && j[i] <= 'z')
                b[j[i] - 'a'] = 1;
            else
                b[j[i] - 'A' + 26] = 1;
        }
        for(int i = 0; i < s.length(); ++i){
            if(s[i] >= 'a' && s[i] <= 'z' && b[s[i] - 'a'])
                ++ans;
            else if(s[i] >= 'A' && s[i] <= 'Z' && b[s[i] - 'A' + 26])
                ++ans;
        }
        return ans;
    }
};
