class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        sum = 0
        for i in range(k):
            sum += calories[i]
        ans = 0
        if sum > upper:
            ans += 1
        elif sum < lower:
            ans -= 1
        for i in range(k, len(calories)):
            sum -= calories[i - k]
            sum += calories[i]
            if sum > upper:
                ans += 1
            elif sum < lower:
                ans -= 1
        return ans
