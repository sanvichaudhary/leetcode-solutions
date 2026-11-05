
class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {

        // If we have used all brackets, save the combination
        if(s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket if we still have some left
        if(open < n) {
            solve(s + '(', open + 1, close, n);
        }

        // Add closing bracket only if it has an opening partner
        if(close < open) {
            solve(s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();

        // Start with an empty string and zero brackets used
        solve("", 0, 0, n);

        return ans;
    }
};
