class Solution {
public:
    string smallestSubsequence(string t) {
        int n = t.length();
        if(!n)return t;
        vector<int> v(26), h(26);
        string s;
        for(int i = 0; i < n; ++i)
            ++v[t[i] - 'a'];
        for(int i = 0; i < n; ++i){
            --v[t[i] - 'a'];
            if(h[t[i] - 'a'])continue;
            while(!s.empty() && s.back() > t[i] && v[s.back() - 'a']){
                --h[s.back() - 'a'];
                s.pop_back();
            }
            s += t[i];
            ++h[t[i] - 'a'];
        }
        return s;
    }
};
