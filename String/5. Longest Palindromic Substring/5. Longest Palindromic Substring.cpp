class Solution {
private:
    int start = 0;
    int maxLen = 0;
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        for (int i = 0; i < s.length() - 1; i++) {
            solution(s, i, i);
            solution(s, i, i+1);
        }
        return s.substr(start, maxLen);
    }
    void solution(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxLen) {
            maxLen = right - left - 1;
            start = left + 1;
        }
    }
};