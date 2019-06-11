class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        if(!n)return "";
        string c;
        stack<char> st;
        for(int i = 0; i < n; ++i){
            if(!st.empty() && st.top() == s[i])st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            c += st.top();
            st.pop();
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
