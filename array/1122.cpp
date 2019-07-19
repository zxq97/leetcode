class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        map<int, int> m;
        for(int i : a)
            ++m[i];
        int j = 0;
        for(int i = 0; i < b.size(); ++i){
            int cnt = m[b[i]];
            for(int k = 0; k < cnt; ++j, ++k)
                a[j] = b[i];
            m.erase(b[i]);
        }
        for(auto i : m)
            for(int k = 0; k < i.second; ++j, ++k)
                a[j] = i.first;
        return a;
    }
};
