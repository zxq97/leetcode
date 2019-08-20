class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        int t = 0;
        for(int i = a.size() - 1; i >= 0; --i){
            int m = k % 10;
            int x = (a[i] + m + t) % 10;
            t = (a[i] + m + t) / 10;
            k /= 10;
            a[i] = x;
        }
        while(t || k){
            int m = k % 10;
            int x = (t + m) % 10;
            t = (t + m) / 10;
            a.insert(a.begin(), x);
            k /= 10;
        }
        return a;
    }
};
