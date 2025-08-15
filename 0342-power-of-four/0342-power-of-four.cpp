class Solution {
public:
    bool isPowerOfFour(int n) {
         if(n == 1)return true;
         for(int i=1;i<=n;i++){
             if(pow(4,i) == n){
                 return true;
                 break;
             }
             else if(pow(4,i) > n){
                 break;
             }
         }
         return false;

    }
};