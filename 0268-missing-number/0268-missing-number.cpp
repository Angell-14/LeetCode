class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Ensure the array is sorted
        sort(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If nums[mid] equals its index, the missing number is on the right
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                // Otherwise, the missing number is on the left
                right = mid - 1;
            }
        }

        return left; // The missing number
    }
};