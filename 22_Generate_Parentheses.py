class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def bp(l,r,s,pos,n,ans):
            if r==n:
                ans.append(''.join(s))
                return 
            if l==r:
                s[pos] = '('
                bp(l+1,r,s,pos+1,n,ans)
            if l>r:
                if l==n:
                    s[pos] = ')'
                    bp(l,r+1,s,pos+1,n,ans)
                else:
                    s[pos] = '('
                    bp(l+1,r,s,pos+1,n,ans)
                    s[pos] = ')'
                    bp(l,r+1,s,pos+1,n,ans)
        
        ans=[]
        bp(0,0,[0]*2*n,0,n,ans)
        return ans
    
