class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        start = 0
        record = {} 
        # [start, start+1, ..., end]
        # record[cur] = start means the repetition occurs at start
        for end in range(len(s)):
            cur = s[end]
            if cur in record and record[cur] >= start:
                print("start: ", start)
                start = record[cur] + 1

            record[cur] = end

            max_len = max(max_len, end - start + 1)
        
        return max_len