class Solution {
public:
    struct cmp{
        bool operator()(char a, char b)const
        {
            return a > b;
        }
    };
    
    int find(const string& s, int idx, char c)
    {
        for(int i = s.length() - 1; i > idx; --i)
            if(s[i] == c)return i;
        return -1;
    }
    
    int maximumSwap(int num) {
        string s = to_string(num);
        string c = s;
        sort(c.begin(), c.end(), cmp());
        for(int i = 0; i < s.length(); ++i)
            if(s[i] != c[i]){
                int idx = find(s, i, c[i]);
                swap(s[idx], s[i]);
                break;
            }
        return atoi(s.c_str());
    }
};
