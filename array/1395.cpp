class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        if(n < 3)return 0;
        vector<int> ll(n), ru(n), lu(n), rl(n);
        for(int i = 0; i < n; ++i){
            int cntl = 0, cntu = 0;
            for(int j = 0; j < n; ++j){
                if(i == j){
                    ll[i] = cntl;
                    lu[i] = cntu;
                    cntl = 0;
                    cntu = 0;
                }
                else{
                    if(r[j] < r[i])++cntl;
                    else if(r[j] > r[i])++cntu;
                }
            }
            rl[i] = cntl;
            ru[i] = cntu;
        }
        int ans = 0;
        for(int i = 1; i < n - 1; ++i)
            ans += ll[i] * ru[i] + lu[i] * rl[i];
        return ans;
    }
};
