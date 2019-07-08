class Solution {
public:
    string toGoatLatin(string s) {
        string t, ans;
        unordered_set<char> se;
        for(int i = 0; i < 5; ++i){
            se.insert(c[i]);
            se.insert(toupper(c[i]));
        }
        string a = "a";
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                if(se.find(t[0]) == se.end()){
                    t += t[0];
                    t.erase(t.begin());
                }
                t += str;
                t += a;
                ans += t;
                ans += s[i];
                a += 'a';
                t = "";
                continue;
            }
            t += s[i];
        }
        if(t.length()){
            if(se.find(t[0]) == se.end()){
                    t += t[0];
                    t.erase(t.begin());
                }
                t += str;
                t += a;
                ans += t;
        }
        return ans;
    }
    
private:
    const char c[6] = "aeiou";
    const string str = "ma";
};
