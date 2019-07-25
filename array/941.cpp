class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n = a.size();
        if(n < 3)return 0;
        int i = 1, j = n - 2;
        for(; i < n && a[i] > a[i - 1]; ++i);
        if(i == n)return 0;
        for(; j >= 0 && a[j] > a[j + 1]; --j);
        if(j == -1)return 0;
        return --i == ++j;
    }
};
