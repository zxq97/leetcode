class Solution {
public:
    bool bfs(const vector<int>& a, const int n, vector<bool>& b, const int idx)
    {
        queue<int> q;
        b[idx] = 1;
        q.push(idx);
        while(!q.empty()){
            if(!a[q.front()])return 1;
            if(q.front() + a[q.front()] < n && !b[q.front() + a[q.front()]]){
                b[q.front() + a[q.front()]] = 1;
                q.push(q.front() + a[q.front()]);
            }
            if(q.front() - a[q.front()] >= 0 && !b[q.front() - a[q.front()]]){
                b[q.front() - a[q.front()]] = 1;
                q.push(q.front() - a[q.front()]);
            }
            q.pop();
        }
        return 0;
    }
    
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        if(n <= start || start < 0)return 0;
        vector<bool> b(n);
        return bfs(a, n, b, start);
    }
};
