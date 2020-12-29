class Solution {
public:
    int fib(int n) {
        if(!n)return 0;
        unsigned long long a[3] = {0, 0, 0};
        a[0] = 1;
        a[1] = 1;
        if(n < 3)return 1;
        const unsigned long long mod = 1e9 + 7;
        for(int i = 3; i <= n; ++i){
            a[2] = (a[0] + a[1]) % mod;
            a[0] = a[1];
            a[1] = a[2];
        }
        return a[2] % mod;
    }
};
