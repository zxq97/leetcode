class Solution {
public:
    int kthFactor(int n, int k) {
        if(!n || !k || k > n)return -1;
        int ans = -1;
        for(int i = 1; i <= n; ++i){
            if(n % i == 0)--k;
            if(!k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
