class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0;
        int mn = INT_MAX;

        vector<int> freq(n + 1, 0);

        for (auto &x : items) {
            freq[x[0]]++;
            mx = max(mx, x[0]);
            mn = min(mn, x[1]);
        }

        vector<int> cnt(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<pair<int, int>> v;

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];
            int gain = cnt[factor] - 1;

            if (gain > 0 && price < 2LL * mn) {
                v.push_back({price, gain});
            }
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        long long rem = budget;

        for (auto &x : v) {
            long long take = min((long long)x.second, rem / x.first);

            ans += 2 * take;
            rem -= take * x.first;
        }

        ans += rem / mn;

        return ans;
    }
};