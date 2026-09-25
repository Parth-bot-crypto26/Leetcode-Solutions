class Solution:
    def transformStr(self, s: str, strs: List[str]) -> List[bool]:
        n = len(s)
        oneS = [0]*(n+1)
        for i in range(n):
            oneS[i+1] = oneS[i] + (1 if s[i] == '1' else 0)
        total1s = oneS[n]
        ans = []
        for st in strs:
            fixed1s = st.count('1')
            numQ = st.count('?')
            needed = total1s-fixed1s
            if needed < 0 or needed > numQ:
                ans.append(False)
                continue
            th = numQ-needed
            qIdx = 0
            running1s = 0
            ok = True
            for i in range(n):
                c = st[i]
                if c == '?':
                    val = 1 if qIdx >= th else 0
                    qIdx += 1
                else:
                    val = 1 if c == '1' else 0
                running1s += val
                if running1s > oneS[i+1]:
                    ok = False
                    break
            ans.append(ok)
        return ans
                