class Solution:
    def getCnt(self, s):
        m = {}
        for i in s:
            if i not in m:
                m[i] = 1
            else:
                m[i] += 1
        c = 'z'
        for i in m.keys():
            if i < c:
                c = i
        return m[c]
    
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        q = [0 for i in range(len(queries))]
        w = [0 for i in range(len(words))]
        for i in range(len(q)):
            q[i] = self.getCnt(queries[i])
        for i in range(len(w)):
            w[i] = self.getCnt(words[i])
        ans = [0 for i in range(len(q))]
        for i in range(len(q)):
            cnt = 0
            for j in range(len(w)):
                if q[i] < w[j]:
                    cnt += 1
            ans[i] = cnt
        return ans
