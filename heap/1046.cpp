class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i : stones)
            q.push(i);
        while(!q.empty()){
            if(q.size() == 1)break;
            int y = q.top();
            q.pop();
            int x;
            if(!q.empty())
                x = q.top();
            q.pop();
            if(x == y)continue;
            else q.push(y - x);
        }
        return q.empty() ? 0 : q.top();
    }
};
