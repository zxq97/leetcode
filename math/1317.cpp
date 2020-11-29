class Solution {
public:
    bool isHaveZero(int x)
    {
        while(x){
            if(x % 10 == 0)return 0;
            x /= 10;
        }
        return 1;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        if(n < 2)return {};
        vector<int> ans(2);
        for(int i = 1; i <= (n >> 1); ++i)
            if(isHaveZero(i) && isHaveZero(n - i)){
                ans[0] = i;
                ans[1] = n - i;
                break;
            }
        return ans;
    }
};
