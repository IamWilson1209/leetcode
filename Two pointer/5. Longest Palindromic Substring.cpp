class Solution {
    public:
        /*
            解法：不能用stack或單純雙指標，字可能是從中間開始算
            分Palindromic Substring可能是奇數、偶數長度
            設計演算法，可以用在奇偶長度->用雙指標
            要重複利用->function獨立出來寫
            參數：
            start index: 紀錄子字串開始位置
            max_len: 紀錄長度
            只能遍歷每個字跑一遍看看：for 迴圈
            string s 要重複->function用void
            void function: (const string& s, int left, int right)
                移動左右index直到不符合
                紀錄位置
                更新
        */
        int start = 0;
        int max_len = 0;
        string longestPalindrome(string s) {
            if (s.length() == 1) return s;
            for (int i = 0; i < s.length() - 1; i++) {
                solution(s, i, i);
                solution(s, i, i + 1);
            }
            return s.substr(start, max_len);
        }
        void solution (const string& s, int left, int right) {
            while (left >= 0 && right <= s.length()-1 && s[left] == s[right]) {
                --left;
                ++right;
            }
            if(right - left - 1 > max_len) {
                max_len = right - left - 1;
                start = left + 1;
            }
        }
    };