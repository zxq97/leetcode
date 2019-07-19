class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for(int i = 1; i < n - 1; ++i){
            int j = i - 1, k = i + 1;
            bool left = 0, right = 0;
            for(; j >= 0 && a[j] < a[j + 1]; --j)left = 1;
            for(; k < n && a[k] < a[k - 1]; ++k)right = 1;
            if(left && right)
                ans = max(ans, k - j - 1);
        }
        return ans > 2 ? ans : 0;
    }
};
