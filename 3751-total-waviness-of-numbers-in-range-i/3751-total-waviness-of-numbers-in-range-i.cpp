class Solution {
public:
    int isWaviness(int digit){
         string val = to_string(digit);
         if(val.size()<3)return 0;
         int k =0;
         for(int i=1;i<val.size()-1;i++){
             if((val[i]>val[i-1] && val[i]>val[i+1]) || val[i]<val[i-1] && val[i]<val[i+1]){
                 k++;
             }
         }
        return k;
         
    }
    int totalWaviness(int num1, int num2) {
         int ans =0;
         for(int i=num1;i<=num2;i++){
              int  digit = i;
              ans+=isWaviness(digit);
         }
         return ans;
    }
};