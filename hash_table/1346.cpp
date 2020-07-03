class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        if(!n)return 0;
        unordered_set<int> s;
        int zeroCnt = 0;
        for(int i = 0; i < n; ++i){
            if(!arr[i])++zeroCnt;
            else s.insert(arr[i]);
        }
        for(int i = 0 ; i < n; ++i)
            if(s.find(arr[i] * 2) != s.end())return 1;
        if(zeroCnt >= 2)return 1;
        return 0;
    }
};
