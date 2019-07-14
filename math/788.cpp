class Solution {
public:
    bool isGoodNum(int x, unordered_set<int>& s, unordered_set<int>& h)
    {
        bool flag = 0;
        while(x){
            int t = x % 10;
            x /= 10;
            if(s.find(t) == s.end())return 0;
            if(h.find(t) != h.end())flag = 1;
        }
        return flag;
    }
    
    int rotatedDigits(int n) {
        unordered_set<int> s, h;
        for(int i : a)
            s.insert(i);
        for(int i = 0; i < 4; ++i)
            h.insert(a[i]);
        int ans = 0;
        for(int i = 2; i <= n; ++i)
            if(isGoodNum(i, s, h))++ans;
        return ans;
    }
    
private:
    const int a[7] = {2, 5, 6, 9, 0, 1, 8};
};
