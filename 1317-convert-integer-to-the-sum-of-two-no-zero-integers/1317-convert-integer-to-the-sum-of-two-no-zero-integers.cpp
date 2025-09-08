class Solution {
public:
    bool isdigit(int a , int b){

         while(a>0){
             int digit = a%10;
             if(digit ==0){    
                 return false;
             }
             a = a/10;
         }
         while(b>0){
             int digit = b%10;
             if(digit ==0){
                 return false;
             }
             b = b/10;
         }
         return true;
      
    }
    vector<int> getNoZeroIntegers(int n) {
         vector<int>ans;
         for(int i=1;i<=n/2;i++){
             int a = i;
             int b = n-i;
         

             if(isdigit(a,b) == true){
                 if(a+b == n){
                     ans.push_back(a);
                     ans.push_back(b);
                     break;
                 }
             }
         }
    return ans;

    }
};