class Solution {
  public:
      string multiply(string num1, string num2) {
          /*
          
          初始化：n1 = 2, n2 = 2, res = [0, 0, 0, 0]（長度 2 + 2）
  
          外層迴圈 i = 1 (num1[1] = '2')：
          j = 1：2 × 4 = 8，res[1+1+1] = 8，carry = 0 → res = [0, 0, 0, 8]
          j = 0：2 × 3 = 6，res[1+0+1] = 6，carry = 0 → res = [0, 0, 6, 8]
          結束內層迴圈，res[1] += 0 → res = [0, 0, 6, 8]
          
          外層迴圈 i = 0 (num1[0] = '1')：
          j = 1：1 × 4 = 4，res[0+1+1] = 6 + 4 = 10，res[2] = 0，carry = 1 → res = [0, 0, 0, 8]
          j = 0：1 × 3 = 3 + 1 = 4，res[0+0+1] = 0 + 4 = 4，carry = 0 → res = [0, 4, 0, 8]
          結束內層迴圈，res[0] += 0 → res = [0, 4, 0, 8]
          
          */
          /* 如果是 0 的 case */
          if (num1 == "0" || num2 == "0") return "0";
          
          /* 宣告變數 */
          int n1 = num1.size(), n2 = num2.size();
          vector<int> res(n1 + n2, 0);
  
          /* 對於 num1, num2 兩字串的每個 digit 相乘 */
          for (int i = n1 - 1; i >= 0; i--) {
              int carry = 0;
              for (int j = n2 - 1; j >= 0; j--) {
                  int temp = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0') + carry; /* 當前數字相乘結果 */ 
                  res[i + j + 1] = temp % 10; /* 儲存當前 digit 的結果 */
                  carry = temp / 10; /* 更新carry */
              }
              res[i] += carry; /* 不知什麼意思 */
          }
  
          /* 將 res 轉成 string */
           int idx = 0;
  
           /* 略過前面是 0 的部分不計 */
           while (idx < res.size() - 1 && res[idx] == 0) idx++;
           string ans;
  
           /* 將每個 digit 轉成 character */
           ans.reserve(res.size() - idx);
           for (; idx < res.size(); idx++) {
              ans.push_back(res[idx] + '0'); // 不知道怎麼轉的
           }
  
           return ans;
      }
  };