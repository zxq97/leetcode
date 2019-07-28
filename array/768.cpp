class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if(!n)return 0;
        vector<int> v = arr;
        for(int i = n - 2; i >= 0; --i)
            v[i] = min(v[i], v[i + 1]);
        int ans = 1, val = arr[0];
        for(int i = 1; i < n; ++i){
            if(val <= v[i]){
                ++ans;
                val = arr[i];
            }
            val = max(val, arr[i]);
        }
        return ans;
    }
};
