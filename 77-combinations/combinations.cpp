#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);

        for (int i = 0; i < k; ++i) {
            comb[i] = i + 1;
        }

        while (true) {
            ans.push_back(comb);

            int idx = k - 1;
            while (idx >= 0 && comb[idx] == n - k + 1 + idx) {
                --idx;
            }

            if (idx < 0) break;

            ++comb[idx];
            for (int j = idx + 1; j < k; ++j) {
                comb[j] = comb[j - 1] + 1;
            }
        }

        return ans;
    }
};