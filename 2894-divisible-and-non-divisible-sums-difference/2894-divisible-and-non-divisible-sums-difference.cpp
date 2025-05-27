class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int sum_n=0,sum_m =0;
        for(int i=1;i<=n;i++){
             if(i%m!=0){
                 sum_n+=i;
             }
             else{
                sum_m+=i;
             }
        }
       
        return sum_n - sum_m;
    }
};