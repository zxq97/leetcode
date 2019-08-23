class Solution {
public:

    bool dfs(int i, const vector<int>& bits)
    {
        if(i == -1)return 1;
        bool ans = 0;
        if(!bits[i])
            ans |= dfs(i - 1, bits);
        if(i && bits[i - 1])
            ans |= dfs(i - 2, bits);
        return ans;
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        return dfs(bits.size() - 2, bits);
    }
};
