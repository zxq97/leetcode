class Solution {
public:
    string largestMerge(string s, string c) {
        int n = s.length(), m = c.length();
        if(!n || !m)return n ? c : s;
        string res;
        int i, j;
        for(i = 0, j = 0; i < n && j < m;){
            if(s[i] > c[j])res += s[i++];
            else if(s[i] < c[j])res += c[j++];
            else{
                int k = i + 1, l = j + 1;
                while(k < n && l < m && s[k] == c[l]){
                    ++k;
                    ++l;
                }
                if(s[k] > c[l])res += s[i++];
                else res += c[j++];
            }
        }
        while(i < n)
            res += s[i++];
        while(j < m)
            res += c[j++];
        return res;
    }
};
