class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Sort the array first
        sort(nums.begin(), nums.end());

        // Initially take the sum of first three elements
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            // Check all possible pairs using two pointers
            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // If we found the exact target, return it
                if (sum == target)
                    return sum;

                // Update closest sum if current sum is nearer
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                // If sum is smaller, increase it
                if (sum < target) {
                    left++;
                }

                // If sum is greater, decrease it
                else {
                    right--;
                }
            }
        }

        // Return the closest sum
        return closest;
    }
};