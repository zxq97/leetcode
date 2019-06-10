class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& a) {
        int n = a.size();
        if(n <= 0)return 1;
        int sum = 0;
        for(int i : a)
            sum += i;
        if(sum % 3)return 0;
        sum /= 3;
        int pre = 0;
        bool flag = 0;
        for(int i : a){
            pre += i;
            if(pre == sum)flag = 1;
            else if(pre == (sum << 1) && flag)return 1;
        }
        return 0;
    }
};
