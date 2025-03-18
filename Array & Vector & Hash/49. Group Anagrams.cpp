class Solution {
  public:
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
       /* unordered_map, vector*/
       vector<vector<string>> ans;
       unordered_map<string, vector<string>> comb;
       
       /* for loop all str */
       for (string str : strs) {
          string word = str;
       /* sort each string, check whether same */
          sort(word.begin(), word.end());
       /* if same, insert into map[string]*/
          comb[word].push_back(str);
       }
  
       /* for loop map, insert into vector*/
       for (auto& iter : comb) {
          ans.push_back(iter.second);
       }   
  
       return ans;
      }
  };
  