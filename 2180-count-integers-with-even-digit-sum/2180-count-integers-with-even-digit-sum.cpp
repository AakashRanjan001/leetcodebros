class Solution {
public:
    int countEven(int num) {
        
        int cnt =0;
        for(int i=1;i<=num;i++){
             int number = i;
             int digitsum =0;
             while(number>0){
                 int digit = number%10;
                 digitsum+=digit;
                 number = number/10;
             }
             if(digitsum%2 ==0)cnt++;
        }
        return cnt;
    }
};