class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n = a.size();
        if(n < 3)return 0;
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = n - 1; i >= 2; --i)
            if(a[i] < a[i - 1] + a[i - 2] && a[i] > a[i - 1] - a[i - 2] && 
               a[i - 1] > a[i] - a[i - 2] && a[i - 2] > a[i] - a[i - 1]){
                ans = a[i] + a[i - 1] + a[i - 2];
                break;
            }
        return ans;
    }
};
