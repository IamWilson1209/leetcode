class Solution {
  /*
      注意，只要在終點前超過就算納入前車的fleet
      不是一定要重疊超過終點進去
  */
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
      int num_car = position.size();
      vector<pair<int, int>> record;
      
      for (int i = 0; i < num_car; i++) {
          record.push_back({position[i], speed[i]});
      }

      // sort by position, reversly
      sort(record.rbegin(), record.rend());

      // main algorithm
      double prev_arrival_time = (double)(target - record[0].first)/record[0].second;
      int fleet = 1;
      for (int i = 1; i < num_car; i++) {
          double cur_arrival_time = (double)(target - record[i].first)/record[i].second;
          if (cur_arrival_time > prev_arrival_time) {
              // 當前車無法追上前面的車隊
              fleet++;
              prev_arrival_time = cur_arrival_time;
          }
      }

      return fleet;
  }
};
