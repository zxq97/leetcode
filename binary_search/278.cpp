// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int ans;
        while(l <= r){
            int m = l + ((r - l) >> 1);
            if(isBadVersion(m)){
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};
