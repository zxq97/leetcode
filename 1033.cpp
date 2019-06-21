class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin(), v.end());
        a = v[0];
        b = v[1];
        c = v[2];
        if(a + 1 == b && b + 1 == c)return {0, 0};
        int min = a + 2 == b || b + 2 == c  || a + 1 == b || b + 1 == c ? 1 : 2;
        int max = b - a - 1 + (c - b - 1);
        return {min, max};
    }
};
