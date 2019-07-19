class Solution {
public:
    string defangIPaddr(string s) {
        string c;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '.')
                c += "[.]";
            else
                c += s[i];
        }
        return c;
    }
};
