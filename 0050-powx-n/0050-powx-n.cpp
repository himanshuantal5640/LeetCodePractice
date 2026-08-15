class Solution {
public:
    double pow(double x,long long n){
        if(n == 0){
            return 1;
        }
        //recursive call
        double half = pow(x,n/2);
        //even power
        if(n % 2 == 0){
            return half*half;
        }
        else{
            return x * half * half;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N > 0){
            return pow(x,N);
        }
        //negative power
        return 1.0/pow(x,-N);
    }
};