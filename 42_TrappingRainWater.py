class Solution:
    def trap(self, height: List[int]) -> int:
        n =len(height)
        pMax =  [height[0]]
        for i in range(1,n):
            pMax.append(max(pMax[i-1],height[i]))
        sMax = [height[n-1]]*n
        i = n-2
        while i > -1:
            sMax[i] = max(sMax[i+1],height[i])
            i-=1
        trapped = 0
        for i in range(1,n-1):
            minHeight = min(pMax[i-1],sMax[i+1])
            if height[i] < minHeight:
                trapped += minHeight - height[i]
        return trapped
