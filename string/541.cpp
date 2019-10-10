class Solution {
public:
    void f(string& s, int l, int r)
    {
        while(l < r)
            swap(s[l++], s[r--]);
    }
    
    string reverseStr(string s, int k) {
        if(k >= s.length()){
            f(s, 0, s.length() - 1);
            return s;
        }
        for(int i = 0; i < s.length(); i += (k << 1)){
            if(i + k - 1 >= s.length()){
                f(s, i, s.length() - 1);   
                break;
            }
            f(s, i, i + k - 1);
        }
        return s;
    }
};
