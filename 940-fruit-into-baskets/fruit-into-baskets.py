class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        i, j, ans, n = 0, 0, 0, len(fruits)
        freq = {}
        while i<n :
            if fruits[i] in freq:
                freq[fruits[i]]+=1
            else:
                freq[fruits[i]]=1
            while len(freq)>2:
                freq[fruits[j]]-=1
                if freq[fruits[j]]==0:
                    del freq[fruits[j]]
                j+=1
            ans=max(ans,i-j+1)
            i+=1
        return ans

        