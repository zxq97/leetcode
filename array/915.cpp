class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size();
        vector<int> v(n);
        v[n - 1] = a[n - 1];
        int m = v.back();
        for(int i = n - 2; i >= 0; --i){
            if(a[i] < m)m = a[i];
            v[i] = m;
        }
        int ans = n, b = a[0];
        for(int i = 0; i < n - 1; ++i){
            b = max(b, a[i]);
            if(b <= v[i + 1]){
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
