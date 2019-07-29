class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.length() != guess.length())return "";
        int a = 0, b = 0;
        unordered_map<char, int> m;
        unordered_set<int> s;
        for(int i = 0; i < secret.length(); ++i){
            if(secret[i] == guess[i]){
                ++a;
                s.insert(i);
                continue;
            }
            ++m[secret[i]];
        }
        for(int i = 0; i < guess.length(); ++i){
            if(s.find(i) != s.end())continue;
            if(m.find(guess[i]) != m.end()){
                ++b;
                --m[guess[i]];
                if(!m[guess[i]])m.erase(guess[i]);
            }
        }
        string c = to_string(a);
        c += "A";
        c += to_string(b);
        c += "B";
        return c;
    }
};
