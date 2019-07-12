class Solution {
public:
    void insert(const string& s, unordered_set<char>& se)
    {
        for(int i = 0; i < s.length(); ++i){
            se.insert(s[i]);
            se.insert(toupper(s[i]));
        }
    }
    
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> preSet, inSet, postSet;
        insert(pre, preSet);
        insert(in, inSet);
        insert(post, postSet);
        vector<string> ans;
        for(int i = 0; i < words.size(); ++i){
            int x;
            if(preSet.find(words[i][0]) != preSet.end())x = 0;
            else if(inSet.find(words[i][0]) != inSet.end())x = 1;
            else if(postSet.find(words[i][0]) != postSet.end())x = 2;
            else return {};
            bool flag = 1;
            for(int j = 1; j < words[i].length(); ++j){
                if(!x && preSet.find(words[i][j]) == preSet.end()){
                    flag = 0;
                    break;
                }
                else if(x == 1 && inSet.find(words[i][j]) == inSet.end()){
                    flag = 0;
                    break;
                }
                else if(x == 2 && postSet.find(words[i][j]) == postSet.end()){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans.push_back(words[i]);
        }
        return ans;
    }

private:
    const string pre = "qwertyuiop";
    const string in = "asdfghjkl";
    const string post = "zxcvbnm";
};
