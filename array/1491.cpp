class Solution {
public:
    double average(vector<int>& v) {
        int n = v.size();
        if(!n)return 0;
        int maxVal = *max_element(v.begin(), v.end()), minVal = *min_element(v.begin(), v.end());
        double sum = 0;
        for(int i = 0; i < n; ++i)
            if(v[i] != maxVal && v[i] != minVal)sum += v[i];
        return sum / (n - 2);
    }
};
