/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int dfs(int id, const vector<Employee*>& v)
    {
        int ans = 0;
        vector<int> t;
        for(int i = 0; i < v.size(); ++i)
            if(v[i]->id == id){
                t = v[i]->subordinates;
                ans = v[i]->importance;
                break;
            }
        for(int i = 0; i < t.size(); ++i)
            ans += dfs(t[i], v);
        return ans;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        if(!employees.size())return 0;
        return dfs(id, employees);
    }
};
