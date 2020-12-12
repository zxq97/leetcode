class Solution {
public:
    struct text{
        string s;
        int idx, length;
        
        bool operator<(const text& t) const{
            if(t.length == this->length)return this->idx < t.idx;
            return this->length < t.length;
        }
    }tmp;
    
    string arrangeWords(string t) {
        int n = t.length();
        if(!n)return t;
        vector<text> v;
        string c;
        t[0] += 32;
        for(int i = 0; i < n; ++i){
            if(t[i] != ' ')c += t[i];
            if(t[i] == ' ' || i == n - 1){
                tmp.s = c;
                tmp.idx = i;
                tmp.length = c.length();
                v.push_back(tmp);
                c = "";
            }
        }
        sort(v.begin(), v.end());
        string ans;
        for(int i = 0; i < v.size(); ++i){
            if(i)ans += ' ';
            ans += v[i].s;
        }
        ans[0] -= 32;
        return ans;
    }
};
