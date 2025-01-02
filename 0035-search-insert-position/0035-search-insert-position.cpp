class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0; // Start of the array
        int right = nums.size() - 1; // End of the array

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }

        return left; // Position to insert if target is not found
    }
};