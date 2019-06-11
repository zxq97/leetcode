class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        if(n <= 1)return 0;
        unordered_map<int, int> m;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            time[i] %= 60;
            int need_num = 0;
            if(time[i])need_num = 60 - time[i];
            if(m.find(time[i]) != m.end())cnt += m[time[i]];
            ++m[need_num];
        }
        return cnt;
    }
};
