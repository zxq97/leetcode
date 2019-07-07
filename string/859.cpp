class Solution {
public:
    bool buddyStrings(string a, string b) {
        if(a.length() != b.length())return 0;
        if(a == b){
            unordered_set<char> s;
            for(int i = 0; i < a.length(); ++i){
                if(s.find(a[i]) != s.end())return 1;
                s.insert(a[i]);
            }
            return 0;
        }
        pair<int, int> p;
        int cnt = 0;
        for(int i = 0; i < a.length(); ++i){
            if(a[i] != b[i]){
                if(!cnt){
                    ++cnt;
                    p.first = i;
                }
                else if(cnt == 1){
                    ++cnt;
                    p.second = i;
                }
                else
                    return 0;
            }
        }
        swap(a[p.first], a[p.second]);
        return a == b;
    }
};
