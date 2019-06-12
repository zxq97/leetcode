class Solution {
public:
    bool guess(int m, int d, const vector<int>& weights)
    {
        int n = m;
        for(int i : weights){
            if(n >= i)n -= i;
            else if(i > m)return 0;
            else{
                n = m - i;
                --d;
            }
        }
        return d > 0;
    }
    
    int shipWithinDays(vector<int>& weights, int d) {
        int w = 0;
        for(int i : weights)
            w += i;
        int l = 0, r = w;
        int ans;
        while(l <= r){
            int m = l +((r - l) >> 1);
            if(guess(m, d, weights)){
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
