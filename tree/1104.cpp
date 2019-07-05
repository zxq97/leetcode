class Solution {
public:
    void f(vector<int>& v, int l, int r)
    {
        for(int i = l, j = r; i < j; ++i, --j)
            swap(v[i], v[j]);
    }
    
    vector<int> pathInZigZagTree(int n) {
        int m = 1, deep = 0;
        for(; m <= n; m <<= 1, ++deep);
        vector<int> v(m);
        for(int i = 0; i < m; ++i)
            v[i] = i + 1;
        for(int i = 1; i <= deep; i += 2){
            if(pow(2, i) == m)break;
            f(v, pow(2, i) - 1, pow(2, i + 1) - 2);
        }
        vector<int> ans;
        stack<int> s;
        int idx = m - 1;
        for(; v[idx] != n; --idx);
        for(int i = idx; i >= 0; --i, i >>= 1)
            s.push(v[i]);
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
