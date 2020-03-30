class Solution {
public:
    
    struct cmp{
        int getOne(int n)
        {
            int cnt = 0;
            while(n){
                n &= n - 1;
                ++cnt;
            }
            return cnt;
        }
        
        bool operator()(int a, int b)
        {
            if(getOne(a) == getOne(b))return a < b;
            return getOne(a) < getOne(b);
        }
    };
    
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        if(!n)return {};
        sort(arr.begin(), arr.end(), cmp());
        return arr;
    }
};
