class Solution {
    public:
        // piles = [1,4,3,2], h = 9
        int minEatingSpeed(vector<int>& piles, int h) {
            int left = 1; // 最慢速度最少是1 
            int right = *max_element(piles.begin(), piles.end()); // 最快速度
    
            while (left < right) { 
                int speed = left + (right - left) / 2;
                // 搜尋範圍是 [left, right)
                // left 是包含的，right 是不包含的。
                if (canEat(piles, speed, h)) {
                    // 此速度可以吃完，可以再降速
                    right = speed;
                } else {
                    // 此速度不可以吃完，提升速度
                    // 假如下一個迴圈不行，while終止，
                    // left會停在可行的速度上，speed + 1
                    left = speed + 1;
                }
            }
            // 回傳最小速度
            return left;
        }
        // 算這個速度吃全部，吃不吃得完
        bool canEat(vector<int>& piles, int speed, int& h) {
            int min_eat_time = 0;
            for (int pile : piles) {
                min_eat_time += pile/speed;
                if (pile%speed > 0) min_eat_time++;
            }
            return min_eat_time > h ? false : true;
        }
    };
    