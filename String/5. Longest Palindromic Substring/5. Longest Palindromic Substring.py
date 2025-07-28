class Solution:
    def __init__(self):
        self.start = 0
        self.max_len = 0
 
    def longestPalindrome(self, s: str) -> str:
        """
        找到字符串中最長的回文子串
        時間複雜度: O(n^2)
        空間複雜度: O(1)
        
        使用中心擴展法：
        1. 遍歷每個可能的回文中心
        2. 從中心向兩邊擴展，檢查是否為回文
        3. 記錄最長的回文串位置和長度
        """
        if len(s) == 1:
            return s

        self.start = 0
        self.max_len = 0

        for i in range(len(s) - 1):
            # 檢查奇數長度的回文(中心是一個單字)
            self.expand_around_center(s, i, i)           
            # 檢查偶數長度的回文(中心是兩個單字之間)
            self.expand_around_center(s, i, i+1)

        # python切片語法
        return s[self.start:self.start + self.max_len]

    def expand_around_center(self, s: str, left: int, right: int) -> None:
        """
        從中心向兩邊擴展，找到最長的回文
        
        Args:
            s: 輸入字符串
            left: 左邊界索引
            right: 右邊界索引
        """
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1

        current_len = right - left - 1

        if current_len > self.max_len:
            self.max_len = current_len
            self.start = left + 1