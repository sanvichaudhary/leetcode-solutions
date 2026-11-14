
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string temp = s;

            // Putting letters in alphabetical order
            sort(temp.begin(), temp.end());

            // Same sorted words = same gang 😂
            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
