// class Solution {
// public:
//     bool isPossible(vector<int>& nums, int divisor, int threshold){
//         int sum =0;
//          for(int i=0;i<nums.size();i++){
//               sum+=(nums[i]+divisor -1)/divisor; //ceil(nums[i]/divisor);
//          }
//          if(sum<=threshold)return true;
//          return false;
//     }
//     int smallestDivisor(vector<int>& nums, int threshold) {
         
//          int n = nums.size();
//          int maxi = *max_element(nums.begin(),nums.end());
//          for(int i=1;i<=maxi;i++){
//              if(isPossible(nums,i,threshold)){
//                  return i;
//              }
//          }
//          return -1;
//     }
// };

class Solution {
public:
    bool isPossible(vector<int>& nums, int divisor, int threshold){
        int sum =0;
         for(int i=0;i<nums.size();i++){
              sum+=(nums[i]+divisor -1)/divisor; //ceil(nums[i]/divisor);
         }
         if(sum<=threshold)return true;
         return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
               int n = nums.size();
               int maxi = *max_element(nums.begin(),nums.end());

               int l = 1;
               int h =  maxi;
               int ans;

               while(l<=h){
                 int mid = l+(h-l)/2;
                 if(isPossible(nums,mid,threshold)){
                      ans = mid;
                      h = mid-1;

                 }
                 else{
                     l = mid+1;
                 }
               }
               return ans;
    }
};