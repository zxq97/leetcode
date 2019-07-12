class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return *max_element(nums.begin(), nums.end());
        priority_queue<int, vector<int>, greater<int>> q;
        unordered_set<int> s;
        int i = 0;
        for(; s.size() < 3 && i < n; ++i)
            if(s.find(nums[i]) == s.end()){
                q.push(nums[i]);
                s.insert(nums[i]);
            }
        for(; i < n; ++i)
            if(s.find(nums[i]) == s.end()){
                if(q.top() < nums[i]){
                    q.pop();
                    q.push(nums[i]);
                    s.insert(nums[i]);
                }
            }
        return q.size() == 3 ? q.top() : *max_element(nums.begin(), nums.end());
    }
};
