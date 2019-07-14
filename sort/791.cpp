class Solution {
public:
    void quickSort(string& t, int l, int r)
    {
        if(l >= r)return;
        int i = l, j = r;
        char c = t[l];
        while(i < j){
            while(i < j && m[t[j]] >= m[c])--j;
            while(i < j && m[t[i]] <= m[c])++i;
            if(i < j)
                swap(t[i], t[j]);
        }
        swap(t[l], t[i]);
        quickSort(t, l, i - 1);
        quickSort(t, i + 1, r);
    }
    
    string customSortString(string s, string t) {
        for(int i = 0; i < s.length(); ++i)
            m[s[i]] = i;
        for(int i = 0; i < t.length(); ++i)
            if(m.find(t[i]) == m.end())
                m[t[i]] = -1;
        quickSort(t, 0, t.length() - 1);
        return t;
    }
    
private:
    unordered_map<char, int> m;
};
