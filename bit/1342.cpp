class Solution {
public:
    int numberOfSteps (int num) {
        if(!num)return 0;
        int ans = 0;
        while(num){
            if(num & 1)--num;
            else num >>= 1;
            ++ans;
        }
        return ans;
    }
};
