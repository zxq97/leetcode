class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        if(!n)return s;
        stack<int> st;
        unordered_set<int> se;
        int t = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '('){
                ++t;
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!t)
                    se.insert(i);
                else{
                    --t;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            se.insert(st.top());
            st.pop();
        }
        string c;
        for(int i = 0; i < n; ++i)
            if(se.find(i) == se.end())c += s[i];
        return c;
    }
};
