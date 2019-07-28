class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(!n)return 0;
        int ans = 1;
        vector<int> v(n);
        v.back() = arr.back();
        for(int i = n - 2; i >= 0; --i)
            v[i] = min(v[i + 1], arr[i]);
        int val = arr[0];
        for(int i = 1; i < n; ++i){
            if(v[i] >= val){
                ++ans;
                val = arr[i];
            }
            else
                val = max(val, arr[i]);
        }
        return ans;
    }
};
