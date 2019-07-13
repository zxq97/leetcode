class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        unordered_map<string, int> m;
        vector<string> v;
        for(int i = 0; i < a.size(); ++i)
            m[a[i]] = i;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        for(int i = 0; i < b.size(); ++i)
            if(m.find(b[i]) != m.end())
                q.push({m[b[i]] + i, b[i]});
        v.push_back(q.top().second);
        int idx = q.top().first;
        q.pop();
        while(!q.empty() && q.top().first == idx){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};
