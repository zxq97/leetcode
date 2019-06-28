class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        if(!n)return 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i : heights)
            q.push(i);
        int cnt = 0;
        for(int i : heights){
            if(i != q.top())++cnt;
            q.pop();
        }
        return cnt;
    }
};
