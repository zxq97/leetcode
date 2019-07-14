class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> v(n + 1, inf);
        v[k] = 0;
        int flag = 1;
        while(flag--){
            for(int i = 0; i < times.size(); ++i)
                if(v[times[i][0]] != inf){
                    int t = v[times[i][1]];
                    v[times[i][1]] = min(v[times[i][1]], v[times[i][0]] + times[i][2]);
                    if(t != v[times[i][1]])flag = 1;
                }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(v[i] == inf)return -1;
            ans = max(ans, v[i]);
        }
        return ans;
    }

private:
    const int inf = 0x3fffffff;
};
