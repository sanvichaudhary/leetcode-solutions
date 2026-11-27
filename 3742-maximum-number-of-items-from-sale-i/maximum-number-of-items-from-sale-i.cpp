class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> dp(budget + 1, 0);
        int min_price = budget + 1;

        for (int i = 0; i < n; ++i) {
            int f = items[i][0], p = items[i][1];
            min_price = min(min_price, p);

            int first_gain = 1;
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % f == 0) {
                    first_gain++;
                }
            }

            for (int b = budget; b >= p; --b) {
                dp[b] = max(dp[b], dp[b - p] + first_gain);
            }
        }

        for (int b = min_price; b <= budget; ++b) {
            dp[b] = max(dp[b], dp[b - min_price] + 1);
        }

        return dp[budget];
    }
};