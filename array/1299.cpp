class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n = a.size();
        int m = a.back();
        a.back() = -1;
        for(int i = n - 2; i >= 0; --i){
            int t = a[i];
            a[i] = m;
            m = max(m, t);
        }
        return a;
    }
};
