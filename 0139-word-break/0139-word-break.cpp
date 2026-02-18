class Solution {
public:

    class TrieNode {
    public:
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    TrieNode* root = new TrieNode();
    vector<int> memo;   // -1 = unknown, 0 = false, 1 = true

    void insert(string &word) {
        TrieNode* curr = root;

        for(char c : word) {
            int idx = c - 'a';

            if(curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    // optimized recursion (index based)
    bool wordbreak(string &s, int start) {

        if(start == s.size())
            return true;

        if(memo[start] != -1)
            return memo[start];

        TrieNode* curr = root;

        for(int i = start; i < s.size(); i++) {

            int idx = s[i] - 'a';

            if(curr->child[idx] == NULL)
                break;

            curr = curr->child[idx];

            if(curr->isEnd && wordbreak(s, i + 1))
                return memo[start] = true;
        }

        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        for(string &w : wordDict)
            insert(w);

        memo.assign(s.size(), -1);

        return wordbreak(s, 0);
    }
};
