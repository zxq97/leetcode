class Solution {
public:
    struct node{
        char c;
        int cnt;
        node(){}
        node(char c, int cnt):c(c), cnt(cnt){}
        
        bool operator<(const node& other) const
        {
            return this->cnt < other.cnt;
        }
    }t;
    
    string reorganizeString(string s) {
        if(s.length() < 2)return s;
        vector<int> v(26);
        for(int i = 0; i < s.length(); ++i)
            ++v[s[i] - 'a'];
        priority_queue<node> q;
        for(int i = 0; i < v.size(); ++i)
            if(v[i])q.push(node('a' + i, v[i]));
        string c;
        t = q.top();
        q.pop();
        c += t.c;
        --t.cnt;
        while(!q.empty()){
            c += q.top().c;
            node p = q.top();
            q.pop();
            if(t.cnt > 0)
                q.push(t);
            t = p;
            --t.cnt;
        }
        return t.cnt ? "" : c;
    }
};
