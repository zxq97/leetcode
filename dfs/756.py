class Solution:
    def dfs(self, i, c, s, v):
        if len(s) == 1:
            return 1;
        if i == len(s):
            t = c
            c = ''
            return self.dfs(1, c, t, v)
        for j in range(len(v)):
            if s[i - 1] == v[j][0] and s[i] == v[j][1]:
                c += v[j][2]
                if self.dfs(i + 1, c, s, v):
                    return True
                c = c[:-1]
        return False;
    
    def pyramidTransition(self, s: str, v: List[str]) -> bool:
        if self.dfs(1, '', s, v):
            return True
        return False
        
        
