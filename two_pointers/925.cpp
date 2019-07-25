class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        for(int j = 0; i < name.length() && j < typed.length();){
            if(name[i] == typed[j])++i, ++j;
            else{
                if(j && typed[j] == typed[j - 1])++j;
                else return 0;
            }
        }
        return i == name.length();
    }
};
