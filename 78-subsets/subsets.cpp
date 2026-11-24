#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int total = 1 << n;
        vector<vector<int>> ans;
        ans.reserve(total);

        for (int mask = 0; mask < total; ++mask) {
            vector<int> current;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    current.push_back(nums[i]);
                }
            }
            ans.push_back(move(current));
        }

        return ans;
    }
};