class Solution {
public:
    void dfs(int m, int n, const vector<int>& v, vector<int>& t, vector<int>& res)
    {
        if(m == (1 << n) - 1){
            if(!res.size() || res.size() > t.size())res = t;
            return;
        }
        if(res.size() && res.size() <= t.size())return;
        int bit = 0;
        while((m >> bit) & 1)++bit;
        for(int i = 0; i < v.size(); ++i)
            if((v[i] >> bit) & 1){
                t.push_back(i);
                dfs(m | v[i], n, v, t, res);
                t.pop_back();
            }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> h;
        for(int i = 0; i < req_skills.size(); ++i)
            h[req_skills[i]] = i;
        int n = people.size();
        vector<int> v(n);
        for(int i = 0; i < n; ++i){
            int k = 0;
            for(int j = 0; j < people[i].size(); ++j)
                if(h.find(people[i][j]) != h.end())
                    k |= 1 << h[people[i][j]];
            v[i] = k;
        }
        vector<int> res, t;
        dfs(0, req_skills.size(), v, t, res);
        return res;
    }
};
