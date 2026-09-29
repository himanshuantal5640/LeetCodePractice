class Solution {
public:

    struct Node {
        Node* child[2];

        Node() {
            child[0] = child[1] = NULL;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* curr = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(curr->child[bit] == NULL) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }

    int getMaxXOR(int num) {
        Node* curr = root;
        int ans = 0;

        for(int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // We prefer opposite bit
            int opposite = 1 - bit;

            if(curr->child[opposite] != NULL) {
                ans |= (1 << i);
                curr = curr->child[opposite];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        // Insert all numbers
        for(int num : nums) {
            insert(num);
        }

        int ans = 0;

        // Find best XOR for every number
        for(int num : nums) {
            ans = max(ans, getMaxXOR(num));
        }

        return ans;
    }
};