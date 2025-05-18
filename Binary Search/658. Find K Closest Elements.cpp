class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;
            /* 
                x - arr[mid]: 窗口左端點距離 x 的距離
                arr[mid + k] - x: 窗口右端點距離 x 的距離
            */
            if (x - arr[mid] > arr[mid + k] - x) {
                /* 左端點離x較遠，更新左端點 */
                left = mid + 1;
            } else {
                /* 右端點離x較遠，更新右端點 */
                right = mid;
            }
        }

        vector<int> ans;
        for (int i = left; i < left + k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};