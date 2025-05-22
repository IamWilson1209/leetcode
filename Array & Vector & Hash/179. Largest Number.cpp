class Solution {
  public:
      string largestNumber(vector<int>& nums) {
          vector<string> stringArray;
          for (int num : nums) {
              stringArray.push_back(to_string(num));
          }
  
          /*
              "9" > "5"："95" > "59"
              return [9, 5]
          */
          sort(stringArray.begin(), stringArray.end(), [](const string &a, const string &b) {
              return (b + a) < (a + b);
          });
  
          if (stringArray[0] == "0") {
              return "0";
          }
  
          /*
          ans += "9" → ans = "9"
          ans += "5" → ans = "95"
          */
          string ans;
          for (const string &num : stringArray) {
              ans += num;
          }
  
          return ans;
      }
  
  };