class Solution {
  public:
      bool isAnagram(string s, string t) {
          unordered_map<char, int> myMap;
          for (char& c : s) {
              myMap[c]++;
          }
          for (char& c: t) {
              myMap[c]--;
              if (myMap[c] < 0) return false;
          }
          for (auto& entry : myMap) {
              if (entry.second > 0) return false;
          }
          return true;
      }
  };