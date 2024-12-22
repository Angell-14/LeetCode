class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0; // Edge case: empty array
        }

        int uniqueIndex = 0; // Pointer to place the next unique element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++;          // Move unique index forward
                nums[uniqueIndex] = nums[i]; // Place the next unique element
            }
        }

        return uniqueIndex + 1; // The length of the unique array
    }
};
