class Solution {
public:
    int smallestRangeI(vector<int>& a, int k) {
        int max = *max_element(a.begin(), a.end());
        int min = *min_element(a.begin(), a.end());
        return max - min > (k << 1) ? max - min - (k << 1) : 0;
    }
};
