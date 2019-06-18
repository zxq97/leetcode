class Solution {
public:
    const int inf = 0x7fffffff;
    
    struct trie{
        bool isword;
        trie* child[26];
        trie()
        {
            isword = 0;
            memset(child, 0, sizeof(child));
        }
    };
    
    void insert(const string& s, trie* root)
    {
        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'a';
            if(!root->child[idx])
                root->child[idx] = new trie();
            root = root->child[idx];
        }
        root->isword = 1;
    }
    
    int find(const string& s, trie* root)
    {
        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'a';
            if(!root->child[idx])return -1;
            root = root->child[idx];
            if(root->isword)return i;
        }
        return -1;
    }
    
    string replaceWords(vector<string>& dict, string s) {
        trie* root = new trie();
        for(int i = 0; i < dict.size(); ++i)
            insert(dict[i], root);
        string ans, c;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                int idx = find(c, root);
                if(idx != -1)c = c.substr(0, idx + 1);
                ans += c;
                ans += s[i];
                c = "";
                continue;
            }
            c += s[i];
        }
        int idx = find(c, root); 
        if(idx != -1)c = c.substr(0, idx + 1);
        ans += c;
        return ans;
    }
};
