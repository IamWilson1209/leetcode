class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          unordered_set<int> checkDuplicate;
          for (int num : nums) {
              if (checkDuplicate.find(num) != checkDuplicate.end()) {
                  return true;
              }
              checkDuplicate.insert(num);
          }
          return false;
      }
  };
  