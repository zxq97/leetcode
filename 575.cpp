class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        for(int i : candies)
            ++m[i];
        return min((candies.size() >> 1), m.size()); 
    }
};
