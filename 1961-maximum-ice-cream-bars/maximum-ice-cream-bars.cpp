
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int freq[100001] = {0};

        for(int i = 0; i < costs.size(); i++) {
            freq[costs[i]]++;
        }

        int count = 0;

        for(int i = 1; i <= 100000; i++) {
            while(freq[i] > 0 && coins >= i) {
                coins -= i;
                count++;
                freq[i]--;
            }
        }

        return count;
    }
};
