class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Step 1: initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 2: union
        for (auto &p : allowedSwaps) {
            unionSet(p[0], p[1]);
        }

        // Step 3: group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int mismatch = 0;

        // Step 4: process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    mismatch++;
                }
            }
        }

        return mismatch;
    }
};