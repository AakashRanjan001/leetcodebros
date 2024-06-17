class Solution {
public:
    bool judgeSquareSum(int c) {
        
       int i = 0;
       int j =sqrt(c);

       while(i<=j){
           long asq = i*i;
           long bsq = j*j;
           long sum = asq+bsq;

           if(sum<c){
              i++;
           }
           else if(sum>c){
            j--;
           }
           else if(sum ==c){
            return true;
           }

       }
       return false;
        

    }
};