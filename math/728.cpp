class Solution {
public:
    bool isAnsNum(int x)
    {
        int n = x;
        while(x){
            int t = x % 10;
            if(!t || n % t)return 0;
            x /= 10;
        }
        return 1;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i = left; i <= right; ++i)
            if(isAnsNum(i))
                v.push_back(i);
        return v;
    }
};
