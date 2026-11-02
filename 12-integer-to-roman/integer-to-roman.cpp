
class Solution {
public:
    string intToRoman(int num) {

        // Roman army reporting for duty!
        vector<int> values = {
            1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD", "C", "XC",
            "L", "XL", "X", "IX", "V", "IV", "I"
        };

        string ans = "";

        // Let's convert this number into ancient history
        for (int i = 0; i < values.size(); i++) {

            // Keep adding symbols until the number says enough!
            while (num >= values[i]) {

                ans += symbols[i];  // Roman magic happens here
                num -= values[i];   // Pay the number's debt
            }
        }

        // And just like that, we're Romans now!
        return ans;
    }
};
