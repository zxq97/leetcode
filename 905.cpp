class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n = a.size();
        for(int i = 0, j = n - 1; i < j;){
            while(i < j && !(a[i] & 1))++i;
            while(i < j && (a[j] & 1))--j;
            swap(a[i++], a[j--]);
        }
        return a;
    }
};
