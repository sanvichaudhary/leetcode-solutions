class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.length();
        int m = words.size();
        int len = words[0].length();

        unordered_map<string, int> mp;

        for (string w : words) {
            mp[w]++;
        }

        for (int i = 0; i < len; i++) {

            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j + len <= n; j += len) {

                string word = s.substr(j, len);

                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = j + len;
                }
                else {
                    seen[word]++;
                    count++;

                    while (seen[word] > mp[word]) {
                        string temp = s.substr(left, len);
                        seen[temp]--;
                        count--;
                        left += len;
                    }

                    if (count == m) {
                        ans.push_back(left);

                        string temp = s.substr(left, len);
                        seen[temp]--;
                        count--;
                        left += len;
                    }
                }
            }
        }

        return ans;
    }
};