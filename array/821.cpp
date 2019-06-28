class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> v, ans(n);
        for(int i = 0; i < n; ++i)
            if(s[i] == c)v.push_back(i);
        int idx = -1;
        for(int i = 0; i < n; ++i){
            if(s[i] == c)ans[i] = 0, ++idx;
            else if(i < v[0])ans[i] = v[0] - i;
            else if(i > v.back())ans[i] = i - v.back();
            else{
                if(i > v[idx] && i < v[idx + 1])
                    ans[i] = min(i - v[idx], v[idx + 1] - i);
            }
        }
        return ans;
    }
};
