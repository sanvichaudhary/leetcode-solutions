class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj;

    void dfs(int node, vector<int>& count) {
        answer[node] = 1;

        for (int child : adj[node]) {
            dfs(child, count);
            answer[node] += answer[child];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        answer.resize(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> newParent = parent;
        vector<vector<int>> children(n);

        function<void(int, vector<int>&)> findAncestor =
            [&](int node, vector<int>& last) {
                int ch = s[node] - 'a';

                if (last[ch] != -1)
                    newParent[node] = last[ch];

                int old = last[ch];
                last[ch] = node;

                for (int child : adj[node])
                    findAncestor(child, last);

                last[ch] = old;
            };

        vector<int> last(26, -1);
        findAncestor(0, last);
        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        adj = finalTree;
        vector<int> dummy(26);
        dfs(0, dummy);

        return answer;
    }
};