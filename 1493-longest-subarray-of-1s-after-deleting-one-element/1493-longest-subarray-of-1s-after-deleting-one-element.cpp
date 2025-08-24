// class Solution {
// public: 
//     int findMax(vector<int>& nums, int skip_idx,int n){
//          int currlen = 0;
//          int maxlen = 0;

//          for(int i=0;i<n;i++){
//              if(i == skip_idx)continue;

//              if(nums[i] == 1){
//                  currlen++;
//                  maxlen = max(maxlen,currlen);
//              }
//              else{
//                  currlen = 0;
//              }
//          }
//          return maxlen;
//     }
//     int longestSubarray(vector<int>& nums) {
//          int n = nums.size();
//          int res = 0;
//          int cnt_zero = 0;
//          for(int i=0;i<n;i++){
//              if(nums[i] == 0){
//                 cnt_zero++;
//                  res = max(res,findMax(nums,i,n));
//              }
//          }

//           // ye last wala case hai jisme saara[1,1,1] hai 
//          return cnt_zero == 0 ? n-1 : res;
//     }
// };
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
          int n = nums.size();
          int cnt_zero =0;
          int res = 0;

          int i=0,j=0;
          while(j<n){ 
              if(nums[j] == 1 && cnt_zero<2){
                 
                 res = max(res,j-i);  
                
              }
              else if(nums[j] == 0){
                 cnt_zero++;
                 while(cnt_zero>1){
                     if(nums[i]!=0)i++;
                     else if(nums[i] == 0){
                         i++;
                         cnt_zero--;
                     }
                 }
              }
              j++;

          }
          return res;
    }
};