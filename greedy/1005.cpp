class Solution {
public:
    int find_minabs(const vector<int>& a, int cnt)
    {
        if(cnt == a.size())return a.back() << 1;
        if(!cnt)return a[0] << 1;
        return min(abs(a[cnt]), abs(a[cnt - 1])) << 1;
    }
    
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int n = a.size();
        if(n <= 0 || k > n)return 0;
        int ans = 0;
        if(!k){
            for(int i : a)
                ans += i;
            return ans;
        }
        sort(a.begin(), a.end());
        int cnt = 0;
        for(; cnt < n && a[cnt] < 0; ++cnt);
        if(cnt >= k){
            bool flag = 0;
            for(int i = 0; i < n; ++i){
                if(i == k)flag = 1;
                if(!flag)ans += -a[i];
                else ans += a[i];
            }
        }
        else{
            k -= cnt;
            for(int i : a)
                ans += abs(i);
            if(k & 1)// 奇数
                return ans - find_minabs(a, cnt);
            else //偶数
                return ans;
        }
        return ans;
    }
};
