class Solution {
public:
    bool rotateString(string a, string b) {
        if(a.length() != b.length())return 0;
        a += a;
        for(int i = 0; i <= a.length() - b.length(); ++i)
            if(a[i] == b[0]){
                bool flag = 1;
                for(int j = 0; j < b.length(); ++j)
                    if(a[i + j] != b[j]){
                        flag = 0;
                        break;
                    }
                if(flag)return 1;
            }
        return 0;
    }
};
