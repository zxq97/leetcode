class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5);
        ans.back() = (max_element(count.begin(), count.end()) - count.begin())* 1.0;
        int cnt = 0;
        unsigned long long sum = 0;
        bool flag = 0;
        for(int i = 0; i < count.size(); ++i){
            sum += (unsigned long long)count[i] * i;
            cnt += count[i];
            if(!flag && count[i]){
                flag = 1;
                ans[0] = i * 1.0;
            }
            if(count[i])
                ans[1] = i * 1.0;
        }
        ans[2] = sum * 1.0 / cnt;
        sum = 0;
        flag = 0;
        for(int i = 0; i < count.size(); ++i){
            if(sum + count[i] == (cnt >> 1)){
                int x;
                for(int j = i + 1; j < count.size(); ++j)
                    if(count[j]){
                        x = j;
                        break;
                    }
                if(cnt & 1)
                    ans[3] = x * 1.0;
                else
                    ans[3] = (i + x) * 0.5;
                break;
            }
            else if(sum + count[i] > (cnt >> 1)){
                ans[3] = i * 1.0;
                break;
            }
            if(count[i])sum += count[i];
        }
        return ans;
    }
};
