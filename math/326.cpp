class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0)return 0;
        if(n == 1)return 1;
        unsigned x = 3;
        while(x < n)
            x *= 3;
        return x == n;
    }
};
