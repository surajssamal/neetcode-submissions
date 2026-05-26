class Solution {
public:
        int recurrsion_search(vector<int> &array, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int result;
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            result = recurrsion_search(array, target, left, mid-1);
        } else if (array[mid] < target) {
            result = recurrsion_search(array, target, mid+1, right);
        }
        return result;
        }


    int search(vector<int>& array, int target) {
          return recurrsion_search(array, target, 0, array.size());

    }
};
