#include <string>
#include <vector>
using namespace std;

int findPattern(string& longStr, string& shortStr) {
    int longLength = longStr.length();
    int shortLength = shortStr.length();

    /* 空字串 return 0 */
    if (shortLength == 0) return 0; 

    /* 紀錄最長prefix長度 */
    vector<int> lps(shortLength, 0);
    createLPS(lps, shortStr);

    int si = 0; 
    for (int li = 0; li < longLength; ) { 
        /* 如果比對成功，長短字串index++ */
        if (longStr[li] == shortStr[si]) {
            li++;
            si++;
            if (si == shortLength) return li - shortLength; // 找到匹配，返回起始位置
        }
        /* 比對失敗 */
        else {
            /* 無法回溯，li 前進 */
            if (si == 0) {
                li++; 
            } 
            /* 回溯到 shortStr 的上一個 LPS 位置 */
            else {
                si = lps[si - 1]; 
            }
        }
    }
    /* 未找到匹配 */
    return -1; 
}

void createLPS(vector<int>& lps, string& shortStr) {
    int len = lps.size();
    int prev = 0; // 前一個匹配位置

    for (int index = 1; index < len; ) { 
        /* 如果比對成功，此 index 長度為前一個 LPS + 1 */
        if (shortStr[index] == shortStr[prev]) {
            lps[index] = prev + 1;
            index++;
            prev++;
        }
        /* 如果比對失敗，且 prev 無法再回溯，則當前 index LPS 為 0 */
        else if (prev == 0) {
            lps[index] = 0;
            index++;
        }
        /* 如果比對失敗，且前一個 LPS 不是 0，回溯 prev */
        else {
            prev = lps[prev-1];
        }
    }
}