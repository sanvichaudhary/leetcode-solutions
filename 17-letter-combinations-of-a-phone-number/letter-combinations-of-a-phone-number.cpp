class Solution {
public:
    vector<string> letterCombinations(string digits) {

        // If no digits are given, return an empty list
        if (digits.empty())
            return {};

        // Phone keypad digit-to-letter mapping
        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current = "";

        // Generate all possible combinations
        function<void(int)> solve = [&](int index) {

            // If all digits are used, store the combination
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            // Get letters for the current digit
            string letters = phone[digits[index] - '0'];

            // Try each possible letter
            for (char ch : letters) {

                current.push_back(ch);

                // Move to the next digit
                solve(index + 1);

                // Remove the last letter to try another option
                current.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};