class Solution {
public:
    int mySqrt(int x) { 
        //  return floor(sqrt(x));  // TAREEKAA 1------>

// TAREEKAAA 2------>>>
        // int ans = 1;
        // if(x ==0)return 0;
        // for(int i=1;i<=x;i++){
        //       if(i*i<=x){
        //          ans = i;
        //       }
        //       else{
        //          break;
        //       }
        // }
        // return ans;


  // TAREEKAA 3 ----->
   // we can reduce teh search space by using the binary search 
    int low = 1;
    int high = x;
    int ans = 0;
    while(low<=high){
         int mid =  low + (high - low)/2;
         if(1LL* mid*mid<=x){ // 1LL is long long which is used to avoid integer overflow
            ans = mid;
            low = mid+1;
         }
         else{
             high = mid-1;
         }
    }   
     return ans;
    }
};