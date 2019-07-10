class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0)return 0;
        if(num == 1)return 1;
        long long l = 2, r = num >> 1;
        while(l <= r){
            long long m = l + ((r - l) >> 1);
            if(m * m == num)return 1;
            else if(m * m > num)r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};
