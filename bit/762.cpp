class Solution {
public:
    bool isPrime(int x)
    {
        if(x < 2)return 0;
        for(int i = 2; i <= sqrt(x); ++i)
            if(x % i == 0)return 0;
        return 1;
    }
    
    bool bit(int x)
    {
        int cnt = 0;
        while(x){
            x &= (x - 1);
            ++cnt;
        }
        return isPrime(cnt);
    }
    
    int countPrimeSetBits(int l, int r) {
        int ans = 0;
        for(int i = l; i <= r; ++i)
            if(bit(i))
                ++ans;
        return ans;
    }
};
