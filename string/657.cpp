class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> p(0, 0);
        for(int i = 0; i < moves.length(); ++i){
            switch(moves[i]){
                case 'U':++p.first;break;
                case 'D':--p.first;break;
                case 'L':++p.second;break;
                case 'R':--p.second;break;
            }
        }
        return !p.first && !p.second;
    }
};
