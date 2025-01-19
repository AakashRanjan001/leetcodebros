class Solution {
public:
    int solveUsingRec(int m,int n){
         if(m==0 || n==0 )return 1;

         int moveleft = solveUsingRec(m,n-1);
         int moveup = solveUsingRec(m-1,n);
         return moveleft + moveup;
    }

    int uniquePaths(int m, int n) {
        int ans = solveUsingRec(m-1,n-1);
        return ans;
    }
};