class Solution {
public:
    struct cmp{
          bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
          {
              if(a.first == b.first)return a.second > b.second;
              return a.first > b.first;
          }
    };
    
    vector<vector<int>> groupThePeople(vector<int>& g) {
        if(!g.size())return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        vector<vector<int>> ans;
        for(int i = 0; i < g.size(); ++i)
            q.push({g[i], i});
        while(!q.empty()){
            int cnt = q.top().first, idx = -1;
            vector<int> v;
            while(!q.empty() && cnt--){
                idx = q.top().second;
                v.push_back(idx);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;
    }
};
