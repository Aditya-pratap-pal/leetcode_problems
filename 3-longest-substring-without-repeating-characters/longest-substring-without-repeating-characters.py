class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        freq = {}

        j = 0
        count = 0

        for i in range(len(s)):

            # Add current character
            freq[s[i]] = freq.get(s[i], 0) + 1

            # If duplicate, move j until duplicate is removed
            while freq[s[i]] > 1:
                freq[s[j]] -= 1
                j += 1

            # Current window length
            count = max(count, i - j + 1)

        return count

