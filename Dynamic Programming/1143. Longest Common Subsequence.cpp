class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int len1 = text1.length(), len2 = text2.length();
            int dp[len1 + 1][len2 + 1]; // 表示 text1[0...i-1] 和 text2[0...j-1] 的最長公共子序列長度。
    
            // Initialize the 2D array with zero.
            memset(dp, 0, sizeof dp);
    
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (text1[i-1] == text2[j-1]) {
                        // 找到一樣，用當前字符 + 前面的 LCS
                        // dp[i-1][j-1] 是「去掉當前匹配字符後」的子問題
                        // dp[i-1][j] 是 text1[0...i-2] 和 text2[0...j-1] 的 LCS，包含 text2[j-1]，
                        // 但已經決定用 text2[j-1] 匹配 text1[i-1]，不能重複使用。
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        // 不一樣，取最大值
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
    
            return dp[len1][len2];
    
        }
    };