class Solution {
  public:
      int hammingWeight(int n) {
          /* count number of 1 as ans */
          int count = 0;
          /* while loop n % 2 */
          while (n > 0) {
              count += n%2;
              n /= 2;
          }
          return count;
      }
  };