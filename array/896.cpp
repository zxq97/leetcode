class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int n = a.size();
        if(n <= 2)return 1;
        bool flag;
        for(int i = 1; i < n; ++i){
            if(a[i] == a[i - 1])continue;
            else
                a[i] > a[i - 1] ? flag = 1 : flag = 0;
        }
        for(int i = 1; i < n; ++i){
            if(!flag && a[i] > a[i - 1])return 0;
            else if(flag && a[i] < a[i - 1])return 0;
        }
        return 1;
    }
};
