class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        if(!n)return 0;
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(dominoes[i][0] > dominoes[i][1])
                swap(dominoes[i][0], dominoes[i][1]);
        map<pair<int, int>, int> m;
        for(int i = 0; i < n; ++i)
            ++m[{dominoes[i][0], dominoes[i][1]}];
        for(auto i : m)
            ans += i.second * (i.second - 1) >> 1;
        return ans;
    }
};
