class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        sign = 1
        result = 0

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        while i < len(s) and s[i] == ' ':
            i += 1
        
        if i >= len(s):
            return 0

        if s[i] in ['-', '+']:
            sign = -1 if s[i] == '-' else 1
            i += 1
        
        while i < len(s) and s[i].isdigit():
            result = result * 10 + int(s[i])

            if result > INT_MAX:
                return INT_MAX if sign == 1 else INT_MIN

            i += 1

        return sign * result
        