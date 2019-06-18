
class MapSum {
public:
    struct trie{
        int sum;
        trie* child[26];
        trie()
        {
            sum = 0;
            memset(child, 0, sizeof(child));
        }
    };

    void insert(const string& s, int val, trie* root)
    {
        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'a';
            if(!root->child[idx])
                root->child[idx] = new trie();
            root = root->child[idx];
            if(se.find(s) != se.end())
                root->sum = val;
            else
                root->sum += val;
        }
        se.insert(s);
    }

    int find(const string& s, trie* root)
    {
        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'a';
            if(!root->child[idx])return 0;
            root = root->child[idx];
        }
        return root->sum;
    }

    /** Initialize your data structure here. */
    MapSum() {
        root = new trie();
        se.clear();
    }

    void insert(string key, int val) {
        insert(key, val, root);
    }

    int sum(string prefix) {
        return find(prefix, root);
    }

private:
    trie* root;
    unordered_set<string> se;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
