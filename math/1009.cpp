class Solution {
public:
    int bitwiseComplement(int n) {
        int t = n, m = 0;
        do{
            m |= 1;
            m <<= 1;
            t >>= 1;
        }while(t);
        m >>= 1;
        n ^= m;
        return n;
    }
};
