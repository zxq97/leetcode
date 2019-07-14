class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        vector<int> v(2);
        int cnt = 1;
        int i = 0;
        for(int j = 1; j < s.length(); ++j){
            if(s[j] == s[j - 1])++cnt;
            else{
                if(cnt > 2){
                    v[0] = i;
                    v[1] = j - 1;
                    ans.push_back(v);
                }
                cnt = 1;
                i = j;
            }
        }
        if(cnt > 2){
            v[0] = i;
            v[1] = s.length() - 1;
            ans.push_back(v);
        }
        return ans;
    }
};
