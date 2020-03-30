class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        if(!n)return 0;
        sort(arr.begin(), arr.end());
        int cur = arr[0], cnt = 1, ans = -1;
        for(int i = 1; i < n; ++i){
            if(arr[i] == arr[i - 1])++cnt;
            else{
                if(cnt == cur)
                    ans = cur;
                cnt = 1;
                cur = arr[i];
            }
        }
        if(cur == cnt)ans = cur;
        return ans;
    }
};
