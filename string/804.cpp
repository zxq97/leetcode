class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string m[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> se;
        for(int i = 0; i < words.size(); ++i){
            string t;
            for(int j = 0; j < words[i].length(); ++j)
                t += m[words[i][j] - 'a'];
            se.insert(t);
        }
        return se.size();
    }
};
