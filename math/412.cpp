class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v(n);
        for(int i = 1; i <= n; ++i){
            bool flag = 0;
            if(i % 3 == 0)
                v[i - 1] += "Fizz", flag = 1;
            if(i % 5 == 0)
                v[i - 1] += "Buzz", flag = 1;
            if(!flag)
                v[i - 1] += to_string(i);
        }
        return v;
    }
};
