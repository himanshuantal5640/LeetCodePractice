class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int n = x;
        long long rev = 0;
        while(n != 0){
            int rem = n%10;
            rev = rev*10 + rem;
            n/=10;
        }
        if(x == rev){
            return true;
        }
        return false;
    }
};