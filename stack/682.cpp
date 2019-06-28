class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == "D"){
                s.push(s.top() * 2);
            }
            else if(ops[i] == "C"){
                s.pop();
                
            }
            else if(ops[i] == "+"){
                int a = s.top();
                s.pop();
                int b = a + s.top();
                s.push(a);
                s.push(b);
            }
            else{
                s.push(atoi(ops[i].c_str()));
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};
