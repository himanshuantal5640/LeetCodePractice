class Solution {
public:
    int fibo(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int sum = fibo(n-1) + fibo(n-2);
        return sum;
    }
    int fib(int n) {
        return fibo(n);
    }
};