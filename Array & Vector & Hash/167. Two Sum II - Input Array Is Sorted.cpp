class Solution {
  public:
      vector<int> twoSum(vector<int>& numbers, int target) {
          // <num, index>
          unordered_map<int, int> visited;
          for (int i = 0; i < numbers.size(); i++) {
              int complement = target - numbers[i];
              if (visited.find(complement) != visited.end()) {
                  return {visited[complement] + 1, i + 1};
              } else {
                  visited[numbers[i]] = i;
              }
          }
          return {};
      }
  };
  