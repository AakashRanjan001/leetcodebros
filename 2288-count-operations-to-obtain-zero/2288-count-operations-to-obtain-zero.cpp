class Solution {
public:
    int countOperations(int num1, int num2) {
        long long oper =0;
        while(num1>0 || num2>0){
             
             if(num1 >num2){
                num1 = num1-num2;
                oper++;
             }
             else if(num2 >num1){
                num2 = num2-num1;
                oper++;
             }
             else if(num1 == num2){
                oper+=1;
                break;
             }
        }
        return oper;
    }
};