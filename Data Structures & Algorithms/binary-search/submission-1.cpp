class Solution {
public:
    int search(vector<int>& array, int target) {
        int left = 0, right = array.size();

        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
            return mid;
            } else if (array[mid] > target) {
            right = mid - 1;
            } else {
            left = mid + 1;
            }
        }

        return -1;


    }
};
