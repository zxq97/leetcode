class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r)
    {
        if(l >= r)return;
        int m = nums[l];
        int i = l, j = r;
        while(i < j){
            while(i < j && nums[j] >= m)--j;
            while(i < j && nums[i] <= m)++i;
            if(i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
    
    void merge(vector<int>& nums, vector<int>& tmp, int l, int m, int r)
    {
        int i = l, j = m + 1, k = l;
        while(i <= m && j <= r){
            if(nums[i] < nums[j])tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while(i <= m)
            tmp[k++] = nums[i++];
        while(j <= r)
            tmp[k++] = nums[j++];
        for(i = l; i <= r; ++i)
            nums[i] = tmp[i];
    }
    
    void mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r)
    {
        if(l >= r)return;
        int m = l + ((r - l) >> 1);
        mergeSort(nums, tmp, l, m);
        mergeSort(nums, tmp, m + 1, r);
        merge(nums, tmp, l, m, r);
    }

	void heap(vector<int>& v, int l, int r)
    {
        int val = v[l];
        for(int i = (l << 1) + 1; i <= r; i = (i << 1) + 1){
            if(i < r && v[i] < v[i + 1])++i;
            if(val >= v[i])break;
            v[l] = v[i];
            l = i;
        }
        v[l] = val;
    }
    
    void heapSort(vector<int>& v, int l, int r)
    {
        for(int i = v.size() >> 1; i >= 0; --i)
            heap(v, i, r);
        for(int i = r; i > 0; --i){
            swap(v[0], v[i]);
            heap(v, 0, i - 1);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // quickSort(nums, 0, n - 1);
        vector<int> tmp(n);
        // mergeSort(nums, tmp, 0, n - 1);
        heapSort(nums, 0, n - 1);
        return nums;
    }
};
