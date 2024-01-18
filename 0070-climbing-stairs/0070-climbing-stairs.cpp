class Solution {
public:
    int climbStairs(int n) {
        
if(n==1 ||n==2){
    return n;                   //fibonacci series ka dimaag aaya
}
 int current =0;
        int x = 0;
        int y= 1;
        int sum = x+y;
        for(int i=1;i<n;i++){
            
            x =y;
            y =sum;
            sum = x+y;
        }
        return sum;
    }
};