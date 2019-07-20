class Solution {
public:
    int find(const vector<int>& a, const int x)
    {
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(a[m] < x)l = m + 1;
            else if(a[m] > x)r = m - 1;
            else return m;
        }
        return -1;
    }
    
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int sa = 0, sb = 0;
        for(int i : a)
            sa += i;
        for(int i : b)
            sb += i;
        int m = (sa - sb) / 2;
        vector<int> v(2);
        for(int i = 0; i < a.size(); ++i){
            int idx = find(b, a[i] - m);
            if(idx != -1){
                v[0] = a[i];
                v[1] = b[idx];
                break;
            }
        }
        return v;
    }
};
