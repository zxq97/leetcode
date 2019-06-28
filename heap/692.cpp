class Solution {
public:
    struct node{
        string s;
        int cnt;
        node(const string& s, int cnt):s(s), cnt(cnt){}
        bool operator<(const node& other)const
        {
            if(this->cnt == other.cnt)return this->s > other.s;
            return this->cnt < other.cnt;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(auto i : words)
            ++m[i];
        priority_queue<node> q;
        for(auto i : m)
            q.push(node(i.first, i.second));
        vector<string> ans;
        while(!q.empty() && ans.size() != k){
            ans.push_back(q.top().s);
            q.pop();
        }
        return ans;
    }
};
