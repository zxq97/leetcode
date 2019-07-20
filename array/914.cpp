class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for(int i : deck)
            ++m[i];
        int cnt = deck.size(), s = 0;
        for(auto i : m){
            cnt = min(cnt, i.second);
            s = max(s, i.second);
        }
        if(cnt == 1)return 0;
        for(int i = 2; i <= s; ++i){
            bool flag = 1;
            for(auto it : m)
                if(it.second % i){
                    flag = 0;
                    break;
                }
            if(flag)return 1;
        }
        return 0;
    }
};
