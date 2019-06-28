class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); ++i){
            if(h.size() < k)h.push(nums[i]);
            else {
                if(nums[i] > h.top()){
                    int tmp = h.top();
                    h.pop();
                    h.push(nums[i]);
                    q.push(tmp);
                }
                else
                    q.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(h.size() == k){
            if(val > h.top()){
                int tmp = h.top();
                h.pop();
                h.push(val);
                q.push(tmp);
            }
        }
        else h.push(val);
        return h.top();
    }

private:
    int k;
    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int>> h;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
