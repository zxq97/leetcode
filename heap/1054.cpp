class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
        {
            return a.second < b.second;
        }
    };
    
    vector<int> rearrangeBarcodes(vector<int>& v) {
        int n = v.size();
        if(!n)return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        unordered_map<int, int> m;
        for(int i : v)
            ++m[i];
        for(auto i : m)
            q.push(i);
        vector<int> ans(n);
        pair<int, int> p, t;
        bool flag = 0, f = 0;
        for(int i = 0; i < n; ++i){
            if(flag)f = 1, t = p;
            else f = 0;
            ans[i] = q.top().first;
            if(q.top().second > 1){
                p.first = q.top().first;
                p.second = q.top().second - 1;
                flag = 1;
            }
            else
                flag = 0;
            q.pop();
            if(f)q.push(t);
        }
        return ans;
    }
};
