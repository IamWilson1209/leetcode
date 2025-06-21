class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int buy = INT_MIN; /*「買進」狀態的最大利潤 */
          int sell = 0; /* 「賣出」或「不持有股票」狀態的最大利潤 */
          int prev_sell = 0; /* 前一天的 sell 狀態 */
          int prev_buy; /* 前一天的 buy 狀態 */
  
          for (int price : prices) {
              /* 選擇用昨天賣股票的錢（prev_sell）買新股票（花 price），或者繼續持有昨天買的股票 */
              prev_buy = buy;
              buy = max(prev_sell - price, buy); 
              /* 選擇賣掉昨天買的股票（prev_buy），賺當天的價格（花 price），或者繼續保持昨天賣出的現金 */
              prev_sell = sell;
              sell = max(prev_buy + price, sell);
          }
          return sell;
      }
  };
  /*
      定義狀態：用三個狀態來表示每天的可能情況：
          buy[i]：到第 i 天為止，以「買進」結束的最大利潤
          sell[i]：到第 i 天為止，以「賣出」結束的最大利潤
          rest[i]：到第 i 天為止，以「冷卻」（不交易）結束的最大利潤
      狀態轉移：
          buy[i] = max(rest[i-1] - price, buy[i-1])：買進要從「冷卻」狀態過來，減去當天價格，或保持之前的買進狀態
          sell[i] = max(buy[i-1] + price, sell[i-1])：賣出要從「買進」狀態過來，加上當天價格，或保持之前的賣出狀態
          rest[i] = max(sell[i-1], buy[i-1], rest[i-1])：冷卻可以從任何狀態過來，選最大值
      觀察到 rest[i] = sell[i-1]，因為冷卻狀態的最大利潤來自之前的賣出（賣出後進入冷卻，且賣出利潤 >= 買進或冷卻）。
      於是簡化為：
          buy[i] = max(sell[i-2] - price, buy[i-1])
          sell[i] = max(buy[i-1] + price, sell[i-1])
  */