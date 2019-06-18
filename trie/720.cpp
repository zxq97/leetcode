class Solution {
public:
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
    
    bool find(const string& s, trie* root)
    {
        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'a';
            if(!root->child[idx] || !root->child[idx]->isword)
                return 0;
            root = root->child[idx];
        }
        return root->isword;
    }
    
    string longestWord(vector<string>& words) {
        trie* root = new trie();
        for(int i = 0; i < words.size(); ++i)
            insert(words[i], root);
        string s;
        for(int i = 0; i < words.size(); ++i)
            if(find(words[i], root) && (words[i].length() > s.length() || (words[i].length() == s.length() && words[i] < s)))
                s = words[i];
        return s;
    }
};
