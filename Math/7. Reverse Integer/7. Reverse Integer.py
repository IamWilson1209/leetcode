class Solution:
    def reverse(self, x: int) -> int:
        """
        反轉整數，處理溢出問題
        約束：結果必須在 [-2^31, 2^31-1] 範圍內，否則返回 0
        
        時間複雜度: O(log x) - 數字的位數
        空間複雜度: O(1)
        """
        # 32位整數的範圍
        INT_MAX = 2**31 - 1  # 2147483647
        INT_MIN = -2**31     # -2147483648
        
        total = 0
        is_negative = False
        
        # 處理負數
        if x < 0:
            is_negative = True
            x = -x
        
        while x > 0:
            digit = x % 10
            x = x // 10
            
            # 檢查溢出：在更新 total 之前檢查
            # 如果 total > (INT_MAX - digit) / 10，則會溢出
            if total > (INT_MAX - digit) // 10:
                return 0
            
            total = total * 10 + digit
        
        # 應用符號
        if is_negative:
            total = -total
            # 檢查負數溢出
            if total < INT_MIN:
                return 0
        
        return total