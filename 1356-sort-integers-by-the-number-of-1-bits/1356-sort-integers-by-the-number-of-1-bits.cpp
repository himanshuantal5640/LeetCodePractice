class Solution {
public:
    int countBits(int n) {
        return __builtin_popcount(n);  // GCC built-in function
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            
            if (bitsA == bitsB)
                return a < b;
            
            return bitsA < bitsB;
        });
        
        return arr;
    }
};