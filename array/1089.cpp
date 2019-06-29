class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
            if(!arr[i]){
                for(int j = arr.size() - 1; j > i; --j)
                    arr[j] = arr[j - 1];
                ++i;
            }
    }
};
