class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 1, r = n, ans = n;
        const long long M1 = 1e9 + 7, M2 = 1e9 + 9, B1 = 100003, B2 = 100019;
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p1[i] = p1[i - 1] * B1 % M1;
            p2[i] = p2[i - 1] * B2 % M2;
        }
        auto ok = [&](int len) {
            unordered_map<long long, int> mp;
            long long h1 = 0, h2 = 0;
            for (int i = 0; i < n; i++) {
                h1 = (h1 * B1 + nums[i]) % M1;
                h2 = (h2 * B2 + nums[i]) % M2;
                if (i >= len) {
                    h1 = (h1 - nums[i - len] * p1[len] % M1 + M1) % M1;
                    h2 = (h2 - nums[i - len] * p2[len] % M2 + M2) % M2;
                }
                if (i >= len - 1) mp[(h1 << 32) | h2]++;
            }
            for (auto& [k, v] : mp) if (v == 1) return true;
            return false;
        };
        while (l <= r) {
            int m = (l + r) / 2;
            if (ok(m)) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};