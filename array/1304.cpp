class Solution {
public:
    vector<int> sumZero(int n) {
        if(!n)return {};
        vector<int> ans;
        bool flag = n & 1 ? 1 : 0;
        int start = -(n >> 1), end = n >> 1;
        for(int i = start; i <= end; ++i){
            if(!flag && !i)continue;
            ans.push_back(i);
        }
        return ans;
    }
};
