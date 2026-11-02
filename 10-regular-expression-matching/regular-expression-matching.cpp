
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size(), m = p.size();

        // DP table: no repeating the same drama
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        function<bool(int, int)> solve = [&](int i, int j) -> bool {

            // Pattern finished? Is the string finished too?
            if (j == m) return i == n;

            // Already solved this mystery
            if (dp[i][j] != -1) return dp[i][j] == 1;

            // Dot matches anything. Very flexible :)
            bool first = (i < n && (s[i] == p[j] || p[j] == '.'));

            bool ans;

            // Star = zero or unlimited times. Commitment issues!
            if (j + 1 < m && p[j + 1] == '*') {

                // Ignore it OR keep matching. Your choice!
                ans = solve(i, j + 2) || (first && solve(i + 1, j));
            }
            else {
                // No star? Move on with life.
                ans = first && solve(i + 1, j + 1);
            }

            // Save the result. Brain RAM is limited.
            dp[i][j] = ans;
            return ans;
        };

        // Time to test the relationship between string and pattern
        return solve(0, 0);
    }
};
