class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int t) {
        int n = a.size();
        if(n < k)return 0;
        int ans = 0, sum = 0;
        for(int i = n - 1, j = 0; j < k - 1 && i >= 0; --i, ++j)
            sum += a[i];
        for(int i = n - k; i >= 0; --i){
            sum += a[i];
            if(sum / k >= t)++ans;
            sum -= a[i + k - 1];
        }
        return ans;
    }
};
