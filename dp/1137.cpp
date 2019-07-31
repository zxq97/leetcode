class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(4);
        v[0] = 0;
        v[1] = v[2] = 1;
        v[3] = 2;
        if(n < 4)return v[n];
        for(int i = 3; i <= n; ++i){
            v[3] = v[0] + v[1] + v[2];
            v[0] = v[1];
            v[1] = v[2];
            v[2] = v[3];
        }
        return v[3];
    }
};
