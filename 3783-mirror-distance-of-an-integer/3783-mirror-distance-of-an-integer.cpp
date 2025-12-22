class Solution {
public:
    int mirrorDistance(int n) {
         int revN = 0;
         int oN = n;
         while(n>0){
             int rem = n%10;
             revN = revN*10 + rem;
             n = n/10;
         }
         return abs(revN - oN);
    }
};