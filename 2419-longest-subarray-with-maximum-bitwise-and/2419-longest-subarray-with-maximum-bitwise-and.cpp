// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//          int n = nums.size();
//          int maxi = *max_element(nums.begin(),nums.end());
//          int index = -1;
//          int cnt =0;
//          for(int i=0;i<n;i++){
//              if(nums[i] == maxi){
//                  index = i;
//                  break;
//              }
//          }
//          int j = index;
//          while(j<n){
//              if(nums[j] == maxi){
//                  cnt++;
//                  j++;
//              }
//              else{
//                  break;
//              }
//          }
//          return cnt;

//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0, maxCnt = 0;

        for (int num : nums) {
            if (num == maxi) {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } else {
                cnt = 0;
            }
        }

        return maxCnt;
    }
};
