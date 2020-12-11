class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(!n || !m || n != m)return 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool flag = 0;
        for(int i = 0; i < n; ++i)
            if(s2[i] > s1[i]){
                flag = 1;
                break;
            }
        if(!flag)return 1;
        for(int i = 0; i < n; ++i)
            if(s1[i] > s2[i])return 0;
        return 1;
    }
};
