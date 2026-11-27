class Solution {
public:
    int dp[30][30][31];

    bool solve(string &s1, string &s2, int i, int j, int len) {
        if (s1.substr(i, len) == s2.substr(j, len))
            return true;

        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        int a[26] = {};

        for (int k = 0; k < len; k++) {
            a[s1[i + k] - 'a']++;
            a[s2[j + k] - 'a']--;
        }

        for (int x : a)
            if (x) return dp[i][j][len] = false;

        for (int k = 1; k < len; k++) {
            if (solve(s1, s2, i, j, k) &&
                solve(s1, s2, i + k, j + k, len - k))
                return dp[i][j][len] = true;

            if (solve(s1, s2, i, j + len - k, k) &&
                solve(s1, s2, i + k, j, len - k))
                return dp[i][j][len] = true;
        }

        return dp[i][j][len] = false;
    }

    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, 0, s1.size());
    }
};