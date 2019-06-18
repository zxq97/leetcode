class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n & 1 ? 1 : 0;
        n >>= 1;
        while(n){
            if(flag){
                if(n & 1)return 0;
                flag = 0;
            }
            else{
                if(!(n & 1))return 0;
                flag = 1;
            }
            n >>= 1;
        }
        return 1;
    }
};
