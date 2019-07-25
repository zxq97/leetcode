class Solution {
public:
    string f(string& s)
    {
        string c;
        bool flag = 0, add = 1;
        for(int i = 0; i < s.length(); ++i){
            if(!flag && s[i] == '.')continue;
            else if(!flag && s[i] == '+')add = 0;
            else if(s[i] == '@')flag = 1;
            if(add || flag)
                c += s[i];
        }
        return c;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(int i = 0; i < emails.size(); ++i){
            string str = f(emails[i]);
            s.insert(str);
        }
        return s.size();
    }
};
