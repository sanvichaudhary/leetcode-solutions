
class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to keep track of opening brackets

        for(char c : s) {

            // If opening bracket comes, save it in the stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // Closing bracket without an opening one? Invalid!
                if(st.empty()) return false;

                // Check the last opening bracket we saved
                char top = st.top();
                st.pop();

                // Brackets must match their pairs
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // No leftover opening brackets means everything is balanced
        return st.empty();
    }
};
