class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        min_str = min(strs, key=len)

        for i in range(len(min_str)):
            current_char = min_str[i]
            for s in strs:
                if s[i] != current_char:
                    print(min_str[:i])
                    return min_str[:i]

        return min_str