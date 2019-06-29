class Solution {
public:
    const string str = "123450";
    string c;
    unordered_set<string> se;
    string to_str(const vector<vector<int>>& board)
    {
        string s = "";
        for(int i = 0;i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                s += board[i][j] + '0';
        return s;
    }
    struct puzzle{
        string s;
        int step;
    };
    int getzero(const string& s)
    {
        for(int i = 0;i < s.length(); ++i)
            if(s[i] == '0')return i;
        return -1;
    }
    string h(int idx)
    {
        string s;
        switch(idx){
            case 0:s = "13";break;
            case 1:s = "024";break;
            case 2:s = "15";break;
            case 3:s = "04";break;
            case 4:s = "135";break;
            case 5:s = "24";break;
        }
        return s;
    }
    void sw(string& s, int i, int j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        return;
    }
    int bfs()
    {
        puzzle n;
        n.step = 0;
        n.s = c;
        queue<puzzle> q;
        q.push(n);
        while(!q.empty()){
            puzzle t = q.front();
            q.pop();
            int idx = getzero(t.s);
            string s = h(idx);
            for(int i = 0; i < s.length(); ++i){
                string st = t.s;
                sw(st, idx, s[i]-'0');
                if(se.find(st) == se.end()){
                    se.insert(st);
                    n.s = st;
                    n.step = t.step+1;
                    q.push(n);
                    if(n.s == str)return n.step;
                }
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        c = to_str(board);
        if(c == str)return 0;
        se.insert(c);
        return bfs();
    }
};
