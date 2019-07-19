class Solution {
public:
    void dfs(int i, const vector<vector<int>>& e, vector<bool>& b)
    {
        b[i] = 1;
        for(int j : e[i])
            if(!b[j])
                dfs(j, e, b);
    }
    
    bool isFinish(const vector<bool>& b)
    {
        for(int i = 0; i < b.size(); ++i)
            if(!b[i])return 0;
        return 1;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n <= 1)return 1;
        vector<bool> b(n);
        dfs(0, rooms, b);
        return isFinish(b);
    }
};
