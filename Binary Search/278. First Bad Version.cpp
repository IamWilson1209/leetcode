// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
  public:
      int firstBadVersion(int n) {
          int left = 1, right = n;
          while (left < right) {
              int mid = left + (right - left) / 2;
              if (!isBadVersion(mid)) { // good
                  left = mid + 1;
              } else {
                  right = mid;
              }
          }
          return left;
      }
  };