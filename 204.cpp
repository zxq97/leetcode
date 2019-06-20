class Solution {
public:
    int countPrimes(int n) {
        vector<bool> b(n + 1);
        int ans = 0;
        for(int i = 2; i < n; ++i)
            if(!b[i]){
                ++ans;
                int m = 2;
                while(i * m < n)
                    b[i * m++] = 1;
            }
        return ans;
    }
};
