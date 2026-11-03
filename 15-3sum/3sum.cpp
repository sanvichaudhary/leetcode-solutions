class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // First, sort the array to make finding pairs easier
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate numbers to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            // Check pairs using two pointers
            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // If sum is zero, we found our triplet
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }

                // Sum is too small, move left pointer forward
                else if (sum < 0) {
                    left++;
                }

                // Sum is too large, move right pointer backward
                else {
                    right--;
                }
            }
        }

        // Return all unique triplets
        return ans;
    }
};