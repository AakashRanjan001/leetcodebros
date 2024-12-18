class Solution {
public:
    int solveUsingRec(int start , int end){
         //base case 
          if(start>=end){ //koi valid number nhi hai ya toh ek hi number hai 
             return 0;     // agr ek hi number hai toh koi penalty nhi lagegi number pakka sahi guess hoga
          }

          int ans = INT_MAX;
          for(int i=start;i<=end;i++){
            // harr ek i ko try karke uska answer nikala aur uska mininmum find outkar liya 
             ans = min(ans , i+max(solveUsingRec(start,i-1) ,solveUsingRec(i+1 ,end)));
          }

       return ans;
    }
    int getMoneyAmount(int n) {
        int ans = solveUsingRec(1,n);
        return ans;
    }
};