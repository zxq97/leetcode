class Solution {
public:
    bool guess(int m, const vector<int>& p, const int h)
    {
        int cnt = 0;
        for(int i : p)
            cnt += max(1, (int)(ceil(i * 1.0 / m)));
        return cnt <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        for(int i : piles)
            r = max(r, i);
        if(h == piles.size())return r;
        int ans;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(guess(m, piles, h)){
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};
