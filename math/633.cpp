class Solution {
public:
    bool judgeSquareSum(int c) {
        if(!c)return 1;
        for(int i = 1; i <= sqrt(c); ++i){
            int x = sqrt(c - i * i);
            if(c - x * x == i * i)return 1;
        }
        return 0;
    }
};
