class Solution {
public:
    long long mod = 1e9 + 7;
    long long solve(long long i,long long n){
        //base case
        if(n == 0){
            return 1;
        }
        long long half = solve(i,n/2);
        if(n%2 == 0){
            return (half*half)%mod;
        }
        return (i*half*half)%mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long ans = solve(5,even);//even index 5 option
        ans = (ans* solve(4,odd))%mod;//odd index 4 option
        return ans;
    }
};