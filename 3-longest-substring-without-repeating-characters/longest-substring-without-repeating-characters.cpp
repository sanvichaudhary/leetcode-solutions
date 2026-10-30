
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        unordered_set<char> st; // No duplicate entries allowed!

        for (int right = 0; right < s.size(); right++) {
            
            while (st.count(s[right])) {
                st.erase(s[left]); // Duplicate found? Someone has to leave!
                left++;
            }

            st.insert(s[right]); // Welcome, new character!
            ans = max(ans, right - left + 1); // Update the record.
        }

        return ans; // Finally, the winner!
    }
};
