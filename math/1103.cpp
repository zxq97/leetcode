class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> v(num_people);
        int cnt = 1;
        for(int i = 0; candies; ++i, i %= num_people){
            if(candies > cnt){
                candies -= cnt;
                v[i] += cnt++;
            }
            else{
                v[i] += candies;
                break;
            }
        }
        return v;
    }
};
