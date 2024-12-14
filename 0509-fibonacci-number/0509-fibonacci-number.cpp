class Solution {
public:
   int getRecSolve(int n){
       // base case
        if(n == 0 || n==1){
             return n;
        }
        int ans = getRecSolve(n-1) + getRecSolve(n-2);
        return ans;
     
   }
    int fib(int n) {
         int ans = getRecSolve(n);
         return ans;
    }
};