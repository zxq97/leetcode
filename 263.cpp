class Solution {
public:
    bool isUgly(int num) {
        if(!num)return 0;
        const int a[3] = {2, 3, 5};
        for(int i = 0; i < 3; ++i)
            while(num % a[i] == 0)
                num /= a[i];
        return num == 1;
    }
};
