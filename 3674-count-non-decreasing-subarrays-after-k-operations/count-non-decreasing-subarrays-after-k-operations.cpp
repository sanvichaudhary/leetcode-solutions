
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        deque<pair<int, int>> dq;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int count = 1;

            while (!dq.empty() && dq.back().first < nums[i]) {

                int num = dq.back().first;
                int cnt = dq.back().second;

                dq.pop_back();

                count += cnt;
                cost += 1LL * (nums[i] - num) * cnt;
            }

            dq.push_back({nums[i], count});

            while (cost > k) {

                int num = dq.front().first;
                int cnt = dq.front().second;

                dq.pop_front();

                cost -= num - nums[j];
                j--;

                if (cnt > 1) {
                    dq.push_front({num, cnt - 1});
                }
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
