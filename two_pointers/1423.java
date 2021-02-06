class Solution {

    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        if(n == 0 || k == 0)return 0;
        if(k == 1)return Math.max(cardPoints[0], cardPoints[n - 1]);
        int[] a = new int[k << 1];
        for(int i = 0, j = n - k; j < n; ++i, ++j)
            a[i] = cardPoints[j];
        for(int i = k, j = 0; j < k; ++i, ++j)
            a[i] = cardPoints[j];
        int sum = 0, ans = 0;
        for(int i = 0; i < k; ++i)
            sum += a[i];
        ans = sum;
        for(int i = k, j = 0; i < a.length; ++i, ++j){
            sum += a[i];
            sum -= a[j];
            ans = Math.max(sum, ans);
        }
        return ans;
    }
}
